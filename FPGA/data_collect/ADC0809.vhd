library IEEE;
use IEEE.std_logic_1164.all;

entity ADC0809 is
	port(D:in std_logic_vector(7 downto 0);
		  CLK,RST:in std_logic;
		  EOC:in std_logic;
		  ALE:out std_logic;
		  START,OE:out std_logic;
		  ADDA,LOCK_T:out std_logic;
		  Q:out std_logic_vector(7 downto 0));
end ADC0809;

architecture behav of ADC0809 is
	type states is (s0,s1,s2,s3,s4);
	signal cs,ns:states:=s0;
	signal REGL:std_logic_vector(7 downto 0);
	signal LOCK:std_logic;
	begin
		ADDA<='0';LOCK_T<=LOCK;
		COM:process(cs,EOC)
			 begin
				case cs is
					when s0=>ALE<='0';START<='0';OE<='0';LOCK<='0';ns<=s1;
					when s1=>ALE<='1';START<='1';OE<='0';LOCK<='0';ns<=s2;
					when s2=>ALE<='0';START<='0';OE<='0';LOCK<='0';
					if(EOC='1')then 
						ns<=s3;
					else 
						ns<=s2;
					end if;
					when s3=>ALE<='0';START<='0';OE<='1';LOCK<='0';ns<=s4;
					when s4=>ALE<='0';START<='0';OE<='1';LOCK<='1';ns<=s0;
					when others=>ALE<='0';START<='0';OE<='0';LOCK<='0';ns<=s0;
				end case;
		end process COM;
		REG:process(CLK,RST)
			 begin
				if(RST='1')then
					cs<=s0;
				elsif(CLK'event and CLK='1')then
					cs<=ns;
				end if;
		end process REG;
		LATCH1:process(LOCK)
				 begin
					if(LOCK='1' and LOCK'event)then
						REGL<=D;
					end if;
		end process LATCH1;
		Q<=REGL;
end behav;
				
					
					
				
				
				
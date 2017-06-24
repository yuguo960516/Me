library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.ALL;

package pack is
	subtype cov_data is integer range 0 to 9;
	type data_array is array(0 to 2) of cov_data;
	function convert(D:in std_logic_vector(7 downto 0)) return data_array;
end;
package body pack is
	function convert(D:in std_logic_vector(7 downto 0)) return data_array is
		variable dat:data_array;
		variable datc:cov_data;
		variable odata:integer range 255 downto 0;
		begin
			odata:=conv_integer(D);
			dat(0):=odata rem 10;
			datc:=odata rem 100;
			dat(1):=datc mod 10;
			dat(2):=odata mod 100;
			return dat;
	end function convert;
end;	

library IEEE;
use IEEE.std_logic_1164.all;
use work.pack.all;

entity shuma is
	port(CLK1,RST1:in std_logic;
		  DATA:in std_logic_vector(7 downto 0);
		  WEI:out std_logic_vector(5 downto 0);
		  DUAN:out std_logic_vector(7 downto 0));
end shuma;

architecture behave of shuma is
	type sta is (st0,st1,st2,st3,st4,st5,st6,st7);
	type ramduan is array(0 to 9) of std_logic_vector(7 downto 0);
	type ramwei is array(0 to 5) of std_logic_vector(5 downto 0);
	signal cs,ns:sta:=st0;
	signal MEMduan:ramduan;
	signal MEMwei:ramwei;
	begin
		MEMduan(0)<=b"11000000";
		MEMduan(1)<=b"11111001";
		MEMduan(2)<=b"10100100";
		MEMduan(3)<=b"10110000";
		MEMduan(4)<=b"10011001";
		MEMduan(5)<=b"10010010";
		MEMduan(6)<=b"10000010";
		MEMduan(7)<=b"11111000";
		MEMduan(8)<=b"10001000";
		MEMduan(9)<=b"10010000";
		
		MEMwei(0)<=b"000001";
		MEMwei(1)<=b"000010";
		MEMwei(2)<=b"000100";
		MEMwei(3)<=b"001000";
		MEMwei(4)<=b"010000";
		MEMwei(5)<=b"100000";
		
		COM:process(cs)
			 variable d:data_array;
			 begin	
				d:=convert(DATA);
				case cs is
					when st0=>WEI<=MEMwei(0);DUAN<=MEMduan(d(0));ns<=st1;
					when st1=>WEI<=MEMwei(1);DUAN<=MEMduan(d(1));ns<=st2;
					when st2=>WEI<=MEMwei(2);DUAN<=MEMduan(d(2));ns<=st3;
					when st3=>WEI<=MEMwei(3);DUAN<=b"10000000";ns<=st4;
					when st4=>WEI<=MEMwei(4);DUAN<=b"10000000";ns<=st5;
					when st5=>WEI<=MEMwei(5);DUAN<=b"10000000";ns<=st0;
					when others=>WEI<=MEMwei(5);DUAN<=b"10000000";ns<=st0;
				end case;
		end process COM;
		REG:process(CLK1,RST1)
			 begin
				if(RST1='1')then
					cs<=st0;
				elsif(CLK1'event and CLK1='1')then
					cs<=ns;
				end if;
		end process REG;	
end behave;		
		

			
						  
	
	
library IEEE;
use IEEE.std_logic_1164.all;

entity data_collect is
	port(D0:in std_logic_vector(7 downto 0);
		  CLK0,RST0:in std_logic;
		  EOC0:in std_logic;
		  ALE0:out std_logic;
		  START0,OE0:out std_logic;
		  ADDA0:out std_logic;
		  WEI0:out std_logic_vector(5 downto 0);
		  DUAN0:out std_logic_vector(7 downto 0));
end data_collect;

architecture G of data_collect is
	component ADC0809
		port(D:in std_logic_vector(7 downto 0);
			  CLK,RST:in std_logic;
			  EOC:in std_logic;
			  ALE:out std_logic;
			  START,OE:out std_logic;
			  ADDA,LOCK_T:out std_logic;
			  Q:out std_logic_vector(7 downto 0));
	end component;
	component shuma
		port(CLK1,RST1:in std_logic;
			  DATA:in std_logic_vector(7 downto 0);
			  WEI:out std_logic_vector(5 downto 0);
			  DUAN:out std_logic_vector(7 downto 0));
	end component;
	signal net:std_logic_vector(7 downto 0);
	begin
		u1:ADC0809 port map(D=>D0,
								  CLK=>CLK0,
								  RST=>RST0,
								  EOC=>EOC0,
								  ALE=>ALE0,
								  START=>START0,
								  OE=>OE0,
								  ADDA=>ADDA0,
								  Q=>net);
		u2:shuma port map(CLK1=>CLK0,
							   RST1=>RST0,
								DATA=>net,
								WEI=>WEI0,
								DUAN=>DUAN0);
end G;				
				  
			  
			  
			  
			  
			  
			  
			  
			  
			  
			  
			  
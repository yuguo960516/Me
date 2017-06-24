-- Copyright (C) 2016  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Intel and sold by Intel or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 16.1.0 Build 196 10/24/2016 SJ Lite Edition"

-- DATE "06/08/2017 13:30:58"

-- 
-- Device: Altera EP4CE6F17C8 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_C1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_D2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_H1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_F16,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	data_collect IS
    PORT (
	D0 : IN std_logic_vector(7 DOWNTO 0);
	CLK0 : IN std_logic;
	RST0 : IN std_logic;
	EOC0 : IN std_logic;
	ALE0 : OUT std_logic;
	START0 : OUT std_logic;
	OE0 : OUT std_logic;
	ADDA0 : OUT std_logic;
	WEI0 : OUT std_logic_vector(5 DOWNTO 0);
	DUAN0 : OUT std_logic_vector(7 DOWNTO 0)
	);
END data_collect;

-- Design Ports Information
-- ALE0	=>  Location: PIN_K11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- START0	=>  Location: PIN_R16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- OE0	=>  Location: PIN_G16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ADDA0	=>  Location: PIN_M9,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[0]	=>  Location: PIN_K16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[1]	=>  Location: PIN_J16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[2]	=>  Location: PIN_J11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[3]	=>  Location: PIN_N14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[4]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- WEI0[5]	=>  Location: PIN_P16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[0]	=>  Location: PIN_L16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[1]	=>  Location: PIN_J14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[2]	=>  Location: PIN_J13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[3]	=>  Location: PIN_L15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[4]	=>  Location: PIN_K15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[5]	=>  Location: PIN_L13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[6]	=>  Location: PIN_L14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- DUAN0[7]	=>  Location: PIN_R10,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- CLK0	=>  Location: PIN_E1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- RST0	=>  Location: PIN_M2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- EOC0	=>  Location: PIN_F13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[0]	=>  Location: PIN_P15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[1]	=>  Location: PIN_P11,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[7]	=>  Location: PIN_G15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[6]	=>  Location: PIN_B16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[5]	=>  Location: PIN_N15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[4]	=>  Location: PIN_J15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[3]	=>  Location: PIN_J12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0[2]	=>  Location: PIN_R13,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF data_collect IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_D0 : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_CLK0 : std_logic;
SIGNAL ww_RST0 : std_logic;
SIGNAL ww_EOC0 : std_logic;
SIGNAL ww_ALE0 : std_logic;
SIGNAL ww_START0 : std_logic;
SIGNAL ww_OE0 : std_logic;
SIGNAL ww_ADDA0 : std_logic;
SIGNAL ww_WEI0 : std_logic_vector(5 DOWNTO 0);
SIGNAL ww_DUAN0 : std_logic_vector(7 DOWNTO 0);
SIGNAL \u1|cs.s4~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \RST0~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \CLK0~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \ALE0~output_o\ : std_logic;
SIGNAL \START0~output_o\ : std_logic;
SIGNAL \OE0~output_o\ : std_logic;
SIGNAL \ADDA0~output_o\ : std_logic;
SIGNAL \WEI0[0]~output_o\ : std_logic;
SIGNAL \WEI0[1]~output_o\ : std_logic;
SIGNAL \WEI0[2]~output_o\ : std_logic;
SIGNAL \WEI0[3]~output_o\ : std_logic;
SIGNAL \WEI0[4]~output_o\ : std_logic;
SIGNAL \WEI0[5]~output_o\ : std_logic;
SIGNAL \DUAN0[0]~output_o\ : std_logic;
SIGNAL \DUAN0[1]~output_o\ : std_logic;
SIGNAL \DUAN0[2]~output_o\ : std_logic;
SIGNAL \DUAN0[3]~output_o\ : std_logic;
SIGNAL \DUAN0[4]~output_o\ : std_logic;
SIGNAL \DUAN0[5]~output_o\ : std_logic;
SIGNAL \DUAN0[6]~output_o\ : std_logic;
SIGNAL \DUAN0[7]~output_o\ : std_logic;
SIGNAL \CLK0~input_o\ : std_logic;
SIGNAL \CLK0~inputclkctrl_outclk\ : std_logic;
SIGNAL \EOC0~input_o\ : std_logic;
SIGNAL \u1|Selector0~0_combout\ : std_logic;
SIGNAL \RST0~input_o\ : std_logic;
SIGNAL \RST0~inputclkctrl_outclk\ : std_logic;
SIGNAL \u1|cs.s2~q\ : std_logic;
SIGNAL \u1|ns.s3~0_combout\ : std_logic;
SIGNAL \u1|cs.s3~q\ : std_logic;
SIGNAL \u1|cs.s4~feeder_combout\ : std_logic;
SIGNAL \u1|cs.s4~q\ : std_logic;
SIGNAL \u1|cs.s0~0_combout\ : std_logic;
SIGNAL \u1|cs.s0~feeder_combout\ : std_logic;
SIGNAL \u1|cs.s0~q\ : std_logic;
SIGNAL \u1|cs.s1~0_combout\ : std_logic;
SIGNAL \u1|cs.s1~q\ : std_logic;
SIGNAL \u1|OE~combout\ : std_logic;
SIGNAL \u2|cs.st1~0_combout\ : std_logic;
SIGNAL \u2|cs.st1~q\ : std_logic;
SIGNAL \u2|cs.st2~q\ : std_logic;
SIGNAL \u2|cs.st3~q\ : std_logic;
SIGNAL \u2|cs.st4~feeder_combout\ : std_logic;
SIGNAL \u2|cs.st4~q\ : std_logic;
SIGNAL \u2|cs.st5~feeder_combout\ : std_logic;
SIGNAL \u2|cs.st5~q\ : std_logic;
SIGNAL \u2|cs.st0~0_combout\ : std_logic;
SIGNAL \u2|cs.st0~q\ : std_logic;
SIGNAL \u1|cs.s4~clkctrl_outclk\ : std_logic;
SIGNAL \D0[7]~input_o\ : std_logic;
SIGNAL \D0[6]~input_o\ : std_logic;
SIGNAL \D0[5]~input_o\ : std_logic;
SIGNAL \D0[4]~input_o\ : std_logic;
SIGNAL \D0[3]~input_o\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~9\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[54]~10_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[54]~11_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[53]~12_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[53]~13_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[52]~15_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[52]~14_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[51]~17_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[51]~16_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\ : std_logic;
SIGNAL \D0[2]~input_o\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\ : std_logic;
SIGNAL \D0[1]~input_o\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[48]~8_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[48]~9_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~7\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ : std_logic;
SIGNAL \D0[0]~input_o\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[56]~26_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[56]~25_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0_combout\ : std_logic;
SIGNAL \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\ : std_logic;
SIGNAL \u2|Mux15~0_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ : std_logic;
SIGNAL \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\ : std_logic;
SIGNAL \u2|Mux23~0_combout\ : std_logic;
SIGNAL \u2|Selector13~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~7\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~9\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~11\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[54]~79_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[54]~92_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[53]~93_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[53]~80_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[52]~81_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[52]~94_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[51]~95_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[51]~82_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~5\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\ : std_logic;
SIGNAL \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\ : std_logic;
SIGNAL \u2|Mux7~0_combout\ : std_logic;
SIGNAL \u2|Selector13~1_combout\ : std_logic;
SIGNAL \u2|Selector12~0_combout\ : std_logic;
SIGNAL \u2|Selector12~2_combout\ : std_logic;
SIGNAL \u2|Selector12~1_combout\ : std_logic;
SIGNAL \u2|Selector12~3_combout\ : std_logic;
SIGNAL \u2|Selector11~2_combout\ : std_logic;
SIGNAL \u2|Selector11~0_combout\ : std_logic;
SIGNAL \u2|Selector11~1_combout\ : std_logic;
SIGNAL \u2|Selector11~3_combout\ : std_logic;
SIGNAL \u2|Mux20~0_combout\ : std_logic;
SIGNAL \u2|Mux12~0_combout\ : std_logic;
SIGNAL \u2|Selector10~0_combout\ : std_logic;
SIGNAL \u2|Mux4~0_combout\ : std_logic;
SIGNAL \u2|Selector10~1_combout\ : std_logic;
SIGNAL \u2|Selector9~0_combout\ : std_logic;
SIGNAL \u2|Selector9~1_combout\ : std_logic;
SIGNAL \u2|Selector9~2_combout\ : std_logic;
SIGNAL \u2|Selector9~3_combout\ : std_logic;
SIGNAL \u2|Mux10~0_combout\ : std_logic;
SIGNAL \u2|Mux18~0_combout\ : std_logic;
SIGNAL \u2|Selector8~0_combout\ : std_logic;
SIGNAL \u2|Mux2~0_combout\ : std_logic;
SIGNAL \u2|Selector8~1_combout\ : std_logic;
SIGNAL \u2|Mux1~0_combout\ : std_logic;
SIGNAL \u2|Mux17~0_combout\ : std_logic;
SIGNAL \u2|Mux9~0_combout\ : std_logic;
SIGNAL \u2|Selector7~0_combout\ : std_logic;
SIGNAL \u2|Selector7~1_combout\ : std_logic;
SIGNAL \u1|REGL\ : std_logic_vector(7 DOWNTO 0);
SIGNAL \u2|ALT_INV_cs.st0~q\ : std_logic;
SIGNAL \ALT_INV_RST0~inputclkctrl_outclk\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_D0 <= D0;
ww_CLK0 <= CLK0;
ww_RST0 <= RST0;
ww_EOC0 <= EOC0;
ALE0 <= ww_ALE0;
START0 <= ww_START0;
OE0 <= ww_OE0;
ADDA0 <= ww_ADDA0;
WEI0 <= ww_WEI0;
DUAN0 <= ww_DUAN0;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\u1|cs.s4~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \u1|cs.s4~q\);

\RST0~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \RST0~input_o\);

\CLK0~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \CLK0~input_o\);
\u2|ALT_INV_cs.st0~q\ <= NOT \u2|cs.st0~q\;
\ALT_INV_RST0~inputclkctrl_outclk\ <= NOT \RST0~inputclkctrl_outclk\;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X34_Y6_N16
\ALE0~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u1|cs.s1~q\,
	devoe => ww_devoe,
	o => \ALE0~output_o\);

-- Location: IOOBUF_X34_Y5_N16
\START0~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u1|cs.s1~q\,
	devoe => ww_devoe,
	o => \START0~output_o\);

-- Location: IOOBUF_X34_Y17_N23
\OE0~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u1|OE~combout\,
	devoe => ww_devoe,
	o => \OE0~output_o\);

-- Location: IOOBUF_X21_Y0_N23
\ADDA0~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => GND,
	devoe => ww_devoe,
	o => \ADDA0~output_o\);

-- Location: IOOBUF_X34_Y9_N16
\WEI0[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|ALT_INV_cs.st0~q\,
	devoe => ww_devoe,
	o => \WEI0[0]~output_o\);

-- Location: IOOBUF_X34_Y9_N2
\WEI0[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|cs.st1~q\,
	devoe => ww_devoe,
	o => \WEI0[1]~output_o\);

-- Location: IOOBUF_X34_Y9_N23
\WEI0[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|cs.st2~q\,
	devoe => ww_devoe,
	o => \WEI0[2]~output_o\);

-- Location: IOOBUF_X34_Y4_N23
\WEI0[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|cs.st3~q\,
	devoe => ww_devoe,
	o => \WEI0[3]~output_o\);

-- Location: IOOBUF_X34_Y7_N23
\WEI0[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|cs.st4~q\,
	devoe => ww_devoe,
	o => \WEI0[4]~output_o\);

-- Location: IOOBUF_X34_Y5_N23
\WEI0[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|cs.st5~q\,
	devoe => ww_devoe,
	o => \WEI0[5]~output_o\);

-- Location: IOOBUF_X34_Y8_N16
\DUAN0[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector13~1_combout\,
	devoe => ww_devoe,
	o => \DUAN0[0]~output_o\);

-- Location: IOOBUF_X34_Y10_N2
\DUAN0[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector12~3_combout\,
	devoe => ww_devoe,
	o => \DUAN0[1]~output_o\);

-- Location: IOOBUF_X34_Y11_N2
\DUAN0[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector11~3_combout\,
	devoe => ww_devoe,
	o => \DUAN0[2]~output_o\);

-- Location: IOOBUF_X34_Y8_N9
\DUAN0[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector10~1_combout\,
	devoe => ww_devoe,
	o => \DUAN0[3]~output_o\);

-- Location: IOOBUF_X34_Y9_N9
\DUAN0[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector9~3_combout\,
	devoe => ww_devoe,
	o => \DUAN0[4]~output_o\);

-- Location: IOOBUF_X34_Y8_N23
\DUAN0[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector8~1_combout\,
	devoe => ww_devoe,
	o => \DUAN0[5]~output_o\);

-- Location: IOOBUF_X34_Y7_N9
\DUAN0[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \u2|Selector7~1_combout\,
	devoe => ww_devoe,
	o => \DUAN0[6]~output_o\);

-- Location: IOOBUF_X21_Y0_N9
\DUAN0[7]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => VCC,
	devoe => ww_devoe,
	o => \DUAN0[7]~output_o\);

-- Location: IOIBUF_X0_Y11_N8
\CLK0~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_CLK0,
	o => \CLK0~input_o\);

-- Location: CLKCTRL_G2
\CLK0~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \CLK0~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \CLK0~inputclkctrl_outclk\);

-- Location: IOIBUF_X34_Y17_N1
\EOC0~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_EOC0,
	o => \EOC0~input_o\);

-- Location: LCCOMB_X33_Y12_N24
\u1|Selector0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|Selector0~0_combout\ = (\u1|cs.s1~q\) # ((!\EOC0~input_o\ & \u1|cs.s2~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \EOC0~input_o\,
	datac => \u1|cs.s2~q\,
	datad => \u1|cs.s1~q\,
	combout => \u1|Selector0~0_combout\);

-- Location: IOIBUF_X0_Y11_N15
\RST0~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_RST0,
	o => \RST0~input_o\);

-- Location: CLKCTRL_G4
\RST0~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \RST0~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \RST0~inputclkctrl_outclk\);

-- Location: FF_X33_Y12_N25
\u1|cs.s2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u1|Selector0~0_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|cs.s2~q\);

-- Location: LCCOMB_X33_Y12_N20
\u1|ns.s3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|ns.s3~0_combout\ = (\EOC0~input_o\ & \u1|cs.s2~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \EOC0~input_o\,
	datad => \u1|cs.s2~q\,
	combout => \u1|ns.s3~0_combout\);

-- Location: FF_X33_Y12_N21
\u1|cs.s3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u1|ns.s3~0_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|cs.s3~q\);

-- Location: LCCOMB_X33_Y12_N14
\u1|cs.s4~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|cs.s4~feeder_combout\ = \u1|cs.s3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u1|cs.s3~q\,
	combout => \u1|cs.s4~feeder_combout\);

-- Location: FF_X33_Y12_N15
\u1|cs.s4\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u1|cs.s4~feeder_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|cs.s4~q\);

-- Location: LCCOMB_X33_Y12_N2
\u1|cs.s0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|cs.s0~0_combout\ = !\u1|cs.s4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|cs.s4~q\,
	combout => \u1|cs.s0~0_combout\);

-- Location: LCCOMB_X33_Y12_N12
\u1|cs.s0~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|cs.s0~feeder_combout\ = \u1|cs.s0~0_combout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|cs.s0~0_combout\,
	combout => \u1|cs.s0~feeder_combout\);

-- Location: FF_X33_Y12_N13
\u1|cs.s0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u1|cs.s0~feeder_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|cs.s0~q\);

-- Location: LCCOMB_X33_Y12_N28
\u1|cs.s1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|cs.s1~0_combout\ = !\u1|cs.s0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u1|cs.s0~q\,
	combout => \u1|cs.s1~0_combout\);

-- Location: FF_X33_Y12_N29
\u1|cs.s1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u1|cs.s1~0_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|cs.s1~q\);

-- Location: LCCOMB_X33_Y12_N0
\u1|OE\ : cycloneive_lcell_comb
-- Equation(s):
-- \u1|OE~combout\ = (\u1|cs.s3~q\) # (\u1|cs.s4~q\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|cs.s3~q\,
	datac => \u1|cs.s4~q\,
	combout => \u1|OE~combout\);

-- Location: LCCOMB_X33_Y8_N14
\u2|cs.st1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|cs.st1~0_combout\ = !\u2|cs.st0~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u2|cs.st0~q\,
	combout => \u2|cs.st1~0_combout\);

-- Location: FF_X33_Y8_N15
\u2|cs.st1\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u2|cs.st1~0_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st1~q\);

-- Location: FF_X33_Y8_N31
\u2|cs.st2\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	asdata => \u2|cs.st1~q\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st2~q\);

-- Location: FF_X33_Y8_N25
\u2|cs.st3\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	asdata => \u2|cs.st2~q\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st3~q\);

-- Location: LCCOMB_X33_Y8_N18
\u2|cs.st4~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|cs.st4~feeder_combout\ = \u2|cs.st3~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u2|cs.st3~q\,
	combout => \u2|cs.st4~feeder_combout\);

-- Location: FF_X33_Y8_N19
\u2|cs.st4\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u2|cs.st4~feeder_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st4~q\);

-- Location: LCCOMB_X33_Y8_N2
\u2|cs.st5~feeder\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|cs.st5~feeder_combout\ = \u2|cs.st4~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u2|cs.st4~q\,
	combout => \u2|cs.st5~feeder_combout\);

-- Location: FF_X33_Y8_N3
\u2|cs.st5\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u2|cs.st5~feeder_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st5~q\);

-- Location: LCCOMB_X33_Y8_N0
\u2|cs.st0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|cs.st0~0_combout\ = !\u2|cs.st5~q\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datad => \u2|cs.st5~q\,
	combout => \u2|cs.st0~0_combout\);

-- Location: FF_X33_Y8_N1
\u2|cs.st0\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \CLK0~inputclkctrl_outclk\,
	d => \u2|cs.st0~0_combout\,
	clrn => \ALT_INV_RST0~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u2|cs.st0~q\);

-- Location: CLKCTRL_G8
\u1|cs.s4~clkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \u1|cs.s4~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \u1|cs.s4~clkctrl_outclk\);

-- Location: IOIBUF_X34_Y17_N15
\D0[7]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(7),
	o => \D0[7]~input_o\);

-- Location: FF_X30_Y11_N5
\u1|REGL[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[7]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(7));

-- Location: IOIBUF_X34_Y18_N1
\D0[6]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(6),
	o => \D0[6]~input_o\);

-- Location: FF_X29_Y11_N29
\u1|REGL[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[6]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(6));

-- Location: IOIBUF_X34_Y7_N15
\D0[5]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(5),
	o => \D0[5]~input_o\);

-- Location: FF_X30_Y11_N7
\u1|REGL[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[5]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(5));

-- Location: IOIBUF_X34_Y10_N8
\D0[4]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(4),
	o => \D0[4]~input_o\);

-- Location: FF_X33_Y11_N3
\u1|REGL[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[4]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(4));

-- Location: IOIBUF_X34_Y11_N8
\D0[3]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(3),
	o => \D0[3]~input_o\);

-- Location: FF_X30_Y11_N15
\u1|REGL[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[3]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(3));

-- Location: LCCOMB_X30_Y11_N14
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\ = \u1|REGL\(3) $ (VCC)
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\ = CARRY(\u1|REGL\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(3),
	datad => VCC,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\);

-- Location: LCCOMB_X30_Y11_N16
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2_combout\ = (\u1|REGL\(4) & (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\ & VCC)) # (!\u1|REGL\(4) & 
-- (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\ = CARRY((!\u1|REGL\(4) & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100000011",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(4),
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~1\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\);

-- Location: LCCOMB_X30_Y11_N18
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4_combout\ = (\u1|REGL\(5) & ((GND) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\))) # (!\u1|REGL\(5) & 
-- (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\ $ (GND)))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\ = CARRY((\u1|REGL\(5)) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101010101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(5),
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~3\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\);

-- Location: LCCOMB_X30_Y11_N20
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6_combout\ = (\u1|REGL\(6) & (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\)) # (!\u1|REGL\(6) & ((\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\) # 
-- (GND)))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\ = CARRY((!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\) # (!\u1|REGL\(6)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(6),
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~5\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\);

-- Location: LCCOMB_X30_Y11_N22
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8_combout\ = (\u1|REGL\(7) & (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\ $ (GND))) # (!\u1|REGL\(7) & 
-- (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\ & VCC))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~9\ = CARRY((\u1|REGL\(7) & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(7),
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~7\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~9\);

-- Location: LCCOMB_X30_Y11_N24
\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\ = !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~9\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~9\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\);

-- Location: LCCOMB_X29_Y11_N10
\u2|Mod1|auto_generated|divider|divider|StageOut[54]~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[54]~10_combout\ = (\u1|REGL\(7) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(7),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[54]~10_combout\);

-- Location: LCCOMB_X30_Y11_N6
\u2|Mod1|auto_generated|divider|divider|StageOut[54]~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[54]~11_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[6]~8_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[54]~11_combout\);

-- Location: LCCOMB_X30_Y11_N8
\u2|Mod1|auto_generated|divider|divider|StageOut[53]~12\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[53]~12_combout\ = (\u1|REGL\(6) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(6),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[53]~12_combout\);

-- Location: LCCOMB_X30_Y11_N30
\u2|Mod1|auto_generated|divider|divider|StageOut[53]~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[53]~13_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[5]~6_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[53]~13_combout\);

-- Location: LCCOMB_X30_Y11_N10
\u2|Mod1|auto_generated|divider|divider|StageOut[52]~15\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[52]~15_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[4]~4_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[52]~15_combout\);

-- Location: LCCOMB_X30_Y11_N28
\u2|Mod1|auto_generated|divider|divider|StageOut[52]~14\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[52]~14_combout\ = (\u1|REGL\(5) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(5),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[52]~14_combout\);

-- Location: LCCOMB_X30_Y11_N2
\u2|Mod1|auto_generated|divider|divider|StageOut[51]~17\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[51]~17_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[3]~2_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[51]~17_combout\);

-- Location: LCCOMB_X30_Y11_N12
\u2|Mod1|auto_generated|divider|divider|StageOut[51]~16\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[51]~16_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\ & \u1|REGL\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	datac => \u1|REGL\(4),
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[51]~16_combout\);

-- Location: LCCOMB_X30_Y11_N0
\u2|Mod1|auto_generated|divider|divider|StageOut[50]~18\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\ = (\u1|REGL\(3) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|REGL\(3),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\);

-- Location: LCCOMB_X30_Y11_N4
\u2|Mod1|auto_generated|divider|divider|StageOut[50]~19\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\);

-- Location: IOIBUF_X28_Y0_N15
\D0[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(2),
	o => \D0[2]~input_o\);

-- Location: FF_X28_Y11_N5
\u1|REGL[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[2]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(2));

-- Location: LCCOMB_X28_Y11_N26
\u2|Mod1|auto_generated|divider|divider|StageOut[49]~20\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\ = (\u1|REGL\(2) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(2),
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\);

-- Location: LCCOMB_X28_Y11_N12
\u2|Mod1|auto_generated|divider|divider|StageOut[49]~21\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\ = (\u1|REGL\(2) & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(2),
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\);

-- Location: LCCOMB_X31_Y11_N0
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\ = (((\u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\)))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ = CARRY((\u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[49]~20_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[49]~21_combout\,
	datad => VCC,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\);

-- Location: LCCOMB_X31_Y11_N2
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ & (((\u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\)))) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\ & 
-- (!\u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\)))
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~5\ = CARRY((!\u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\ & 
-- !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\,
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~3\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~5\);

-- Location: LCCOMB_X31_Y11_N4
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\ = CARRY((\u2|Mod1|auto_generated|divider|divider|StageOut[51]~17_combout\) # ((\u2|Mod1|auto_generated|divider|divider|StageOut[51]~16_combout\) # 
-- (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~5\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[51]~17_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[51]~16_combout\,
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~5\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\);

-- Location: LCCOMB_X31_Y11_N6
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\ = CARRY(((!\u2|Mod1|auto_generated|divider|divider|StageOut[52]~15_combout\ & !\u2|Mod1|auto_generated|divider|divider|StageOut[52]~14_combout\)) # 
-- (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[52]~15_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[52]~14_combout\,
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\);

-- Location: LCCOMB_X31_Y11_N8
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\ = CARRY((!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[53]~12_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[53]~13_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[53]~12_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[53]~13_combout\,
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\);

-- Location: LCCOMB_X31_Y11_N10
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\ = CARRY((!\u2|Mod1|auto_generated|divider|divider|StageOut[54]~10_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[54]~11_combout\ & 
-- !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[54]~10_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[54]~11_combout\,
	datad => VCC,
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\,
	cout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\);

-- Location: LCCOMB_X31_Y11_N12
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ = \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\);

-- Location: LCCOMB_X30_Y11_N26
\u2|Mod1|auto_generated|divider|divider|StageOut[59]~32\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & ((\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\ & (\u1|REGL\(3))) # 
-- (!\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\ & ((\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	datac => \u1|REGL\(3),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[2]~0_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\);

-- Location: LCCOMB_X31_Y11_N24
\u2|Mod1|auto_generated|divider|divider|StageOut[59]~27\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\);

-- Location: LCCOMB_X31_Y11_N14
\u2|Mod1|auto_generated|divider|divider|StageOut[58]~28\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\ = (\u1|REGL\(2) & \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|REGL\(2),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\);

-- Location: LCCOMB_X31_Y11_N28
\u2|Mod1|auto_generated|divider|divider|StageOut[58]~29\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\);

-- Location: IOIBUF_X28_Y0_N22
\D0[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(1),
	o => \D0[1]~input_o\);

-- Location: FF_X28_Y8_N25
\u1|REGL[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[1]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(1));

-- Location: LCCOMB_X31_Y11_N26
\u2|Mod1|auto_generated|divider|divider|StageOut[57]~30\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\ = (\u1|REGL\(1) & \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|REGL\(1),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\);

-- Location: LCCOMB_X26_Y11_N18
\u2|Mod1|auto_generated|divider|divider|StageOut[48]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[48]~8_combout\ = (\u1|REGL\(1) & \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|REGL\(1),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[48]~8_combout\);

-- Location: LCCOMB_X26_Y11_N28
\u2|Mod1|auto_generated|divider|divider|StageOut[48]~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[48]~9_combout\ = (\u1|REGL\(1) & !\u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u1|REGL\(1),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_6_result_int[7]~10_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[48]~9_combout\);

-- Location: LCCOMB_X26_Y11_N16
\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\ = (\u2|Mod1|auto_generated|divider|divider|StageOut[48]~8_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[48]~9_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[48]~8_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[48]~9_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\);

-- Location: LCCOMB_X31_Y11_N20
\u2|Mod1|auto_generated|divider|divider|StageOut[57]~31\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\ & !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\);

-- Location: LCCOMB_X32_Y11_N6
\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2_combout\ = (((\u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\)))
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\ = CARRY((\u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\,
	datad => VCC,
	combout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2_combout\,
	cout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\);

-- Location: LCCOMB_X32_Y11_N8
\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\ & (((\u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\ & 
-- (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\)))
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\ = CARRY((!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\ & 
-- !\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\,
	datad => VCC,
	cin => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~3\,
	combout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4_combout\,
	cout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\);

-- Location: LCCOMB_X32_Y11_N10
\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\ & (((\u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\ & ((((\u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\)))))
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~7\ = CARRY((!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\) # 
-- (\u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\,
	datad => VCC,
	cin => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~5\,
	combout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6_combout\,
	cout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~7\);

-- Location: LCCOMB_X32_Y11_N12
\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ = !\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~7\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~7\,
	combout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\);

-- Location: LCCOMB_X32_Y11_N22
\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\) # 
-- ((\u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & (((\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~31_combout\,
	datac => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~30_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[1]~2_combout\,
	combout => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\);

-- Location: LCCOMB_X32_Y11_N20
\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\) # 
-- ((\u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & (((\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~28_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~29_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[2]~4_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\,
	combout => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\);

-- Location: LCCOMB_X32_Y11_N26
\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\) # 
-- ((\u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & (((\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~27_combout\,
	datac => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~32_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[3]~6_combout\,
	combout => \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\);

-- Location: IOIBUF_X34_Y4_N15
\D0[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_D0(0),
	o => \D0[0]~input_o\);

-- Location: FF_X33_Y8_N29
\u1|REGL[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \u1|cs.s4~clkctrl_outclk\,
	asdata => \D0[0]~input_o\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \u1|REGL\(0));

-- Location: LCCOMB_X33_Y11_N12
\u2|Mod1|auto_generated|divider|divider|StageOut[56]~26\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[56]~26_combout\ = (\u1|REGL\(0) & !\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(0),
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[56]~26_combout\);

-- Location: LCCOMB_X33_Y11_N22
\u2|Mod1|auto_generated|divider|divider|StageOut[56]~25\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[56]~25_combout\ = (\u1|REGL\(0) & \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(0),
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[56]~25_combout\);

-- Location: LCCOMB_X33_Y11_N24
\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0_combout\ = (\u2|Mod1|auto_generated|divider|divider|StageOut[56]~26_combout\) # (\u2|Mod1|auto_generated|divider|divider|StageOut[56]~25_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[56]~26_combout\,
	datac => \u2|Mod1|auto_generated|divider|divider|StageOut[56]~25_combout\,
	combout => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0_combout\);

-- Location: LCCOMB_X32_Y11_N0
\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\ = (\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & (\u1|REGL\(0))) # (!\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\ & 
-- ((\u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110110001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[4]~8_combout\,
	datab => \u1|REGL\(0),
	datad => \u2|Mod2|auto_generated|divider|divider|add_sub_3_result_int[0]~0_combout\,
	combout => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\);

-- Location: LCCOMB_X32_Y11_N4
\u2|Mux15~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux15~0_combout\ = (!\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & (!\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ $ 
-- (\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Mux15~0_combout\);

-- Location: LCCOMB_X31_Y11_N16
\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & ((\u1|REGL\(2)))) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & 
-- (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\,
	datac => \u1|REGL\(2),
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\);

-- Location: LCCOMB_X31_Y11_N30
\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & (\u1|REGL\(1))) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & 
-- ((\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(1),
	datac => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\);

-- Location: LCCOMB_X31_Y11_N22
\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\ = (\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\) # 
-- ((\u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\)))) # (!\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & (((\u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~19_combout\,
	datac => \u2|Mod1|auto_generated|divider|divider|StageOut[50]~18_combout\,
	datad => \u2|Mod1|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\,
	combout => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\);

-- Location: LCCOMB_X33_Y11_N8
\u2|Mux23~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux23~0_combout\ = (!\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ $ (\u1|REGL\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\,
	combout => \u2|Mux23~0_combout\);

-- Location: LCCOMB_X33_Y8_N24
\u2|Selector13~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector13~0_combout\ = (\u2|cs.st1~q\ & ((\u2|Mux15~0_combout\) # ((\u2|cs.st2~q\ & \u2|Mux23~0_combout\)))) # (!\u2|cs.st1~q\ & (((\u2|cs.st2~q\ & \u2|Mux23~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111100010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mux15~0_combout\,
	datac => \u2|cs.st2~q\,
	datad => \u2|Mux23~0_combout\,
	combout => \u2|Selector13~0_combout\);

-- Location: LCCOMB_X29_Y11_N14
\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\ = \u1|REGL\(5) $ (VCC)
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\ = CARRY(\u1|REGL\(5))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(5),
	datad => VCC,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\);

-- Location: LCCOMB_X29_Y11_N16
\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\ = (\u1|REGL\(6) & (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\ & VCC)) # (!\u1|REGL\(6) & 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\ = CARRY((!\u1|REGL\(6) & !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100000011",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(6),
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~1\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\);

-- Location: LCCOMB_X29_Y11_N18
\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\ = (\u1|REGL\(7) & (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\ $ (GND))) # (!\u1|REGL\(7) & 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\ & VCC))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~5\ = CARRY((\u1|REGL\(7) & !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(7),
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~3\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~5\);

-- Location: LCCOMB_X29_Y11_N20
\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ = !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~5\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~5\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\);

-- Location: LCCOMB_X29_Y11_N4
\u2|Mod0|auto_generated|divider|divider|StageOut[27]~54\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & \u1|REGL\(7))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datad => \u1|REGL\(7),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\);

-- Location: LCCOMB_X29_Y11_N22
\u2|Mod0|auto_generated|divider|divider|StageOut[27]~55\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\);

-- Location: LCCOMB_X29_Y11_N6
\u2|Mod0|auto_generated|divider|divider|StageOut[26]~57\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\);

-- Location: LCCOMB_X29_Y11_N8
\u2|Mod0|auto_generated|divider|divider|StageOut[26]~56\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & \u1|REGL\(6))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datad => \u1|REGL\(6),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\);

-- Location: LCCOMB_X29_Y11_N2
\u2|Mod0|auto_generated|divider|divider|StageOut[25]~59\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\);

-- Location: LCCOMB_X29_Y11_N12
\u2|Mod0|auto_generated|divider|divider|StageOut[25]~58\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & \u1|REGL\(5))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datad => \u1|REGL\(5),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\);

-- Location: LCCOMB_X28_Y11_N10
\u2|Mod0|auto_generated|divider|divider|StageOut[24]~60\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & \u1|REGL\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datac => \u1|REGL\(4),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\);

-- Location: LCCOMB_X28_Y11_N8
\u2|Mod0|auto_generated|divider|divider|StageOut[24]~61\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & \u1|REGL\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101000001010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datac => \u1|REGL\(4),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\);

-- Location: LCCOMB_X28_Y11_N14
\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\ = (((\u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[24]~60_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[24]~61_combout\,
	datad => VCC,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\);

-- Location: LCCOMB_X28_Y11_N16
\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[25]~59_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[25]~58_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~1\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\);

-- Location: LCCOMB_X28_Y11_N18
\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\)))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[26]~57_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[26]~56_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~3\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\);

-- Location: LCCOMB_X28_Y11_N20
\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~7\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[27]~54_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[27]~55_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~5\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~7\);

-- Location: LCCOMB_X28_Y11_N22
\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ = \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~7\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~7\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\);

-- Location: LCCOMB_X29_Y11_N24
\u2|Mod0|auto_generated|divider|divider|StageOut[36]~96\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & (\u1|REGL\(7))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(7),
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[3]~4_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\);

-- Location: LCCOMB_X28_Y11_N6
\u2|Mod0|auto_generated|divider|divider|StageOut[36]~62\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\);

-- Location: LCCOMB_X29_Y11_N28
\u2|Mod0|auto_generated|divider|divider|StageOut[35]~97\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & ((\u1|REGL\(6)))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & (\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110010000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[2]~2_combout\,
	datac => \u1|REGL\(6),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\);

-- Location: LCCOMB_X29_Y11_N0
\u2|Mod0|auto_generated|divider|divider|StageOut[35]~63\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\);

-- Location: LCCOMB_X29_Y11_N30
\u2|Mod0|auto_generated|divider|divider|StageOut[34]~64\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\);

-- Location: LCCOMB_X29_Y11_N26
\u2|Mod0|auto_generated|divider|divider|StageOut[34]~98\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & (\u1|REGL\(5))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000100011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(5),
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[1]~0_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_3_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\);

-- Location: LCCOMB_X28_Y11_N0
\u2|Mod0|auto_generated|divider|divider|StageOut[33]~66\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000110000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\);

-- Location: LCCOMB_X28_Y11_N28
\u2|Mod0|auto_generated|divider|divider|StageOut[33]~65\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u1|REGL\(4))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datac => \u1|REGL\(4),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\);

-- Location: LCCOMB_X29_Y10_N26
\u2|Mod0|auto_generated|divider|divider|StageOut[32]~68\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u1|REGL\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datac => \u1|REGL\(3),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\);

-- Location: LCCOMB_X29_Y10_N16
\u2|Mod0|auto_generated|divider|divider|StageOut[32]~67\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u1|REGL\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datac => \u1|REGL\(3),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\);

-- Location: LCCOMB_X29_Y10_N2
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\ = (((\u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[32]~68_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[32]~67_combout\,
	datad => VCC,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\);

-- Location: LCCOMB_X29_Y10_N4
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[33]~66_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[33]~65_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~1\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\);

-- Location: LCCOMB_X29_Y10_N6
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\)))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[34]~64_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~3\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\);

-- Location: LCCOMB_X29_Y10_N8
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[35]~63_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~5\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\);

-- Location: LCCOMB_X29_Y10_N10
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\))))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\) # 
-- ((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\) # (GND))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~9\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\) # ((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111011101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[36]~62_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~7\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~9\);

-- Location: LCCOMB_X29_Y10_N12
\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ = !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~9\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~9\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\);

-- Location: LCCOMB_X29_Y10_N22
\u2|Mod0|auto_generated|divider|divider|StageOut[45]~89\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\) # 
-- ((!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|StageOut[36]~96_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\);

-- Location: LCCOMB_X29_Y10_N0
\u2|Mod0|auto_generated|divider|divider|StageOut[45]~69\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\);

-- Location: LCCOMB_X28_Y11_N2
\u2|Mod0|auto_generated|divider|divider|StageOut[44]~90\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\) # 
-- ((!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[3]~4_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[35]~97_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\);

-- Location: LCCOMB_X29_Y10_N14
\u2|Mod0|auto_generated|divider|divider|StageOut[44]~70\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\);

-- Location: LCCOMB_X29_Y10_N20
\u2|Mod0|auto_generated|divider|divider|StageOut[43]~71\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\);

-- Location: LCCOMB_X28_Y11_N24
\u2|Mod0|auto_generated|divider|divider|StageOut[43]~91\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\) # 
-- ((!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000001000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[2]~2_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[34]~98_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\);

-- Location: LCCOMB_X28_Y11_N30
\u2|Mod0|auto_generated|divider|divider|StageOut[42]~99\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & (\u1|REGL\(4))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[5]~8_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datac => \u1|REGL\(4),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_4_result_int[1]~0_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\);

-- Location: LCCOMB_X28_Y10_N4
\u2|Mod0|auto_generated|divider|divider|StageOut[42]~72\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\);

-- Location: LCCOMB_X29_Y10_N30
\u2|Mod0|auto_generated|divider|divider|StageOut[41]~73\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & \u1|REGL\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datac => \u1|REGL\(3),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\);

-- Location: LCCOMB_X29_Y10_N28
\u2|Mod0|auto_generated|divider|divider|StageOut[41]~74\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\);

-- Location: LCCOMB_X28_Y10_N30
\u2|Mod0|auto_generated|divider|divider|StageOut[40]~75\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\ = (\u1|REGL\(2) & \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(2),
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\);

-- Location: LCCOMB_X28_Y10_N24
\u2|Mod0|auto_generated|divider|divider|StageOut[40]~76\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\ = (\u1|REGL\(2) & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101000001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(2),
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\);

-- Location: LCCOMB_X28_Y10_N10
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0_combout\ = (((\u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[40]~75_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[40]~76_combout\,
	datad => VCC,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\);

-- Location: LCCOMB_X28_Y10_N12
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[41]~73_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[41]~74_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~1\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\);

-- Location: LCCOMB_X28_Y10_N14
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\)))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[42]~72_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~3\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\);

-- Location: LCCOMB_X28_Y10_N16
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[43]~71_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~5\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\);

-- Location: LCCOMB_X28_Y10_N18
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\))))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\) # 
-- ((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\) # (GND))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\) # ((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001111011101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[44]~70_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~7\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\);

-- Location: LCCOMB_X28_Y10_N20
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~11\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[45]~69_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~9\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~11\);

-- Location: LCCOMB_X28_Y10_N22
\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ = \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~11\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011110000",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~11\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\);

-- Location: LCCOMB_X28_Y8_N26
\u2|Mod0|auto_generated|divider|divider|StageOut[48]~77\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\ = (\u1|REGL\(1) & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(1),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\);

-- Location: LCCOMB_X28_Y8_N20
\u2|Mod0|auto_generated|divider|divider|StageOut[48]~78\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\ = (\u1|REGL\(1) & !\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u1|REGL\(1),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\);

-- Location: LCCOMB_X28_Y8_N4
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\ = (((\u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\) # (\u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[48]~77_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[48]~78_combout\,
	datad => VCC,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\);

-- Location: LCCOMB_X28_Y10_N2
\u2|Mod0|auto_generated|divider|divider|StageOut[54]~79\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[54]~79_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[54]~79_combout\);

-- Location: LCCOMB_X29_Y10_N24
\u2|Mod0|auto_generated|divider|divider|StageOut[54]~92\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[54]~92_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\) # 
-- ((\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[5]~8_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|StageOut[45]~89_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[54]~92_combout\);

-- Location: LCCOMB_X28_Y10_N26
\u2|Mod0|auto_generated|divider|divider|StageOut[53]~93\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[53]~93_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\) # 
-- ((\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\ & !\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[44]~90_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[4]~6_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[53]~93_combout\);

-- Location: LCCOMB_X28_Y8_N2
\u2|Mod0|auto_generated|divider|divider|StageOut[53]~80\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[53]~80_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[5]~8_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[53]~80_combout\);

-- Location: LCCOMB_X28_Y10_N0
\u2|Mod0|auto_generated|divider|divider|StageOut[52]~81\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[52]~81_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[4]~6_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[52]~81_combout\);

-- Location: LCCOMB_X28_Y10_N8
\u2|Mod0|auto_generated|divider|divider|StageOut[52]~94\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[52]~94_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\) # 
-- ((!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000101010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[43]~91_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[3]~4_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[52]~94_combout\);

-- Location: LCCOMB_X28_Y10_N6
\u2|Mod0|auto_generated|divider|divider|StageOut[51]~95\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[51]~95_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\) # 
-- ((!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010001010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|StageOut[42]~99_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[2]~2_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[51]~95_combout\);

-- Location: LCCOMB_X28_Y8_N28
\u2|Mod0|auto_generated|divider|divider|StageOut[51]~82\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[51]~82_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[3]~4_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[51]~82_combout\);

-- Location: LCCOMB_X29_Y10_N18
\u2|Mod0|auto_generated|divider|divider|StageOut[50]~100\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & ((\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & ((\u1|REGL\(3)))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\ & (\u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110010000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[6]~10_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_5_result_int[1]~0_combout\,
	datac => \u1|REGL\(3),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\);

-- Location: LCCOMB_X28_Y8_N22
\u2|Mod0|auto_generated|divider|divider|StageOut[50]~83\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[2]~2_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\);

-- Location: LCCOMB_X28_Y10_N28
\u2|Mod0|auto_generated|divider|divider|StageOut[49]~85\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\ = (!\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[1]~0_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\);

-- Location: LCCOMB_X28_Y11_N4
\u2|Mod0|auto_generated|divider|divider|StageOut[49]~84\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\ & \u1|REGL\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_6_result_int[7]~12_combout\,
	datac => \u1|REGL\(2),
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\);

-- Location: LCCOMB_X28_Y8_N6
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\ & 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\)))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~1\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\);

-- Location: LCCOMB_X28_Y8_N8
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ & ((((\u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\)))))
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~5\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110000100001110",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~3\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~5\);

-- Location: LCCOMB_X28_Y8_N10
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[51]~95_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[51]~82_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~5\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[51]~95_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[51]~82_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~5\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\);

-- Location: LCCOMB_X28_Y8_N12
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[52]~81_combout\) # ((\u2|Mod0|auto_generated|divider|divider|StageOut[52]~94_combout\) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[52]~81_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[52]~94_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[4]~7_cout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\);

-- Location: LCCOMB_X28_Y8_N14
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\ = CARRY((!\u2|Mod0|auto_generated|divider|divider|StageOut[53]~93_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[53]~80_combout\ & 
-- !\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000001",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[53]~93_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[53]~80_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[5]~9_cout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\);

-- Location: LCCOMB_X28_Y8_N16
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\ = CARRY((\u2|Mod0|auto_generated|divider|divider|StageOut[54]~79_combout\) # ((\u2|Mod0|auto_generated|divider|divider|StageOut[54]~92_combout\) # 
-- (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011101111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[54]~79_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[54]~92_combout\,
	datad => VCC,
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[6]~11_cout\,
	cout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\);

-- Location: LCCOMB_X28_Y8_N18
\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ = !\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	cin => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[7]~13_cout\,
	combout => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\);

-- Location: LCCOMB_X28_Y8_N24
\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & ((\u1|REGL\(1)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & 
-- (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000011001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[1]~0_combout\,
	datac => \u1|REGL\(1),
	datad => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\);

-- Location: LCCOMB_X28_Y8_N30
\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\) # 
-- ((\u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & (((\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110010111000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~83_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[3]~4_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[50]~100_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\);

-- Location: LCCOMB_X28_Y8_N0
\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\ = (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & (((\u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\) # 
-- (\u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\)))) # (!\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\ & (\u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[2]~2_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|add_sub_7_result_int[8]~14_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~85_combout\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[49]~84_combout\,
	combout => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\);

-- Location: LCCOMB_X33_Y8_N8
\u2|Mux7~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux7~0_combout\ = (!\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & (!\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ & (\u1|REGL\(0) $ (\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	combout => \u2|Mux7~0_combout\);

-- Location: LCCOMB_X33_Y8_N16
\u2|Selector13~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector13~1_combout\ = (\u2|Selector13~0_combout\) # ((\u2|Mux7~0_combout\ & !\u2|cs.st0~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101011111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Selector13~0_combout\,
	datac => \u2|Mux7~0_combout\,
	datad => \u2|cs.st0~q\,
	combout => \u2|Selector13~1_combout\);

-- Location: LCCOMB_X32_Y11_N2
\u2|Selector12~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector12~0_combout\ = (\u2|cs.st1~q\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ $ (\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Selector12~0_combout\);

-- Location: LCCOMB_X33_Y11_N4
\u2|Selector12~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector12~2_combout\ = (\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\ & (!\u2|cs.st0~q\ & (\u1|REGL\(0) $ (\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000010000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(0),
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	datac => \u2|cs.st0~q\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	combout => \u2|Selector12~2_combout\);

-- Location: LCCOMB_X33_Y11_N26
\u2|Selector12~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector12~1_combout\ = (\u2|cs.st2~q\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ $ (\u1|REGL\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st2~q\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	combout => \u2|Selector12~1_combout\);

-- Location: LCCOMB_X33_Y11_N30
\u2|Selector12~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector12~3_combout\ = (\u2|Selector12~0_combout\) # ((\u2|Selector12~2_combout\) # (\u2|Selector12~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111011111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Selector12~0_combout\,
	datab => \u2|Selector12~2_combout\,
	datac => \u2|Selector12~1_combout\,
	combout => \u2|Selector12~3_combout\);

-- Location: LCCOMB_X33_Y11_N10
\u2|Selector11~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector11~2_combout\ = (!\u1|REGL\(0) & (!\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\ & (!\u2|cs.st0~q\ & \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u1|REGL\(0),
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	datac => \u2|cs.st0~q\,
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	combout => \u2|Selector11~2_combout\);

-- Location: LCCOMB_X32_Y11_N24
\u2|Selector11~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector11~0_combout\ = (\u2|cs.st1~q\ & (!\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & !\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Selector11~0_combout\);

-- Location: LCCOMB_X33_Y11_N20
\u2|Selector11~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector11~1_combout\ = (\u2|cs.st2~q\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ & (!\u1|REGL\(0) & !\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st2~q\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	combout => \u2|Selector11~1_combout\);

-- Location: LCCOMB_X33_Y11_N2
\u2|Selector11~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector11~3_combout\ = (\u2|Selector11~2_combout\) # ((\u2|Selector11~0_combout\) # (\u2|Selector11~1_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Selector11~2_combout\,
	datab => \u2|Selector11~0_combout\,
	datad => \u2|Selector11~1_combout\,
	combout => \u2|Selector11~3_combout\);

-- Location: LCCOMB_X33_Y11_N16
\u2|Mux20~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux20~0_combout\ = (\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ $ (!\u1|REGL\(0))))) # 
-- (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ & (\u1|REGL\(0) $ (\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000110010010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\,
	combout => \u2|Mux20~0_combout\);

-- Location: LCCOMB_X32_Y11_N18
\u2|Mux12~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux12~0_combout\ = (\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & (!\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ $ 
-- (!\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\)))) # (!\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & (!\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & 
-- (\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ $ (\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100100010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Mux12~0_combout\);

-- Location: LCCOMB_X33_Y8_N22
\u2|Selector10~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector10~0_combout\ = (\u2|cs.st1~q\ & ((\u2|Mux12~0_combout\) # ((\u2|Mux20~0_combout\ & \u2|cs.st2~q\)))) # (!\u2|cs.st1~q\ & (\u2|Mux20~0_combout\ & ((\u2|cs.st2~q\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110110010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mux20~0_combout\,
	datac => \u2|Mux12~0_combout\,
	datad => \u2|cs.st2~q\,
	combout => \u2|Selector10~0_combout\);

-- Location: LCCOMB_X33_Y8_N4
\u2|Mux4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux4~0_combout\ = (\u1|REGL\(0) & (!\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ & (\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ $ (!\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\)))) # 
-- (!\u1|REGL\(0) & (!\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & (\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ $ (\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000100010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	combout => \u2|Mux4~0_combout\);

-- Location: LCCOMB_X33_Y8_N10
\u2|Selector10~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector10~1_combout\ = (\u2|Selector10~0_combout\) # ((!\u2|cs.st0~q\ & \u2|Mux4~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101010111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Selector10~0_combout\,
	datab => \u2|cs.st0~q\,
	datac => \u2|Mux4~0_combout\,
	combout => \u2|Selector10~1_combout\);

-- Location: LCCOMB_X32_Y11_N16
\u2|Selector9~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector9~0_combout\ = (\u2|cs.st1~q\ & ((\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\) # ((\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & !\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101000001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Selector9~0_combout\);

-- Location: LCCOMB_X33_Y11_N18
\u2|Selector9~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector9~1_combout\ = (\u1|REGL\(0)) # ((\u2|cs.st2~q\ & (!\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ & \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st2~q\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	combout => \u2|Selector9~1_combout\);

-- Location: LCCOMB_X33_Y11_N0
\u2|Selector9~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector9~2_combout\ = (\u2|cs.st0~q\ & (((!\u2|Selector9~1_combout\) # (!\u2|cs.st2~q\)))) # (!\u2|cs.st0~q\ & (\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & ((!\u2|Selector9~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101011101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st0~q\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	datac => \u2|cs.st2~q\,
	datad => \u2|Selector9~1_combout\,
	combout => \u2|Selector9~2_combout\);

-- Location: LCCOMB_X33_Y11_N14
\u2|Selector9~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector9~3_combout\ = (\u2|Selector9~0_combout\) # ((!\u2|Selector9~2_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\) # (\u2|Selector9~1_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011101110111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Selector9~0_combout\,
	datab => \u2|Selector9~2_combout\,
	datac => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	datad => \u2|Selector9~1_combout\,
	combout => \u2|Selector9~3_combout\);

-- Location: LCCOMB_X32_Y11_N14
\u2|Mux10~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux10~0_combout\ = (!\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\ & ((\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & ((\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\) # 
-- (!\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\))) # (!\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & (!\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\ & 
-- \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000101100000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Mux10~0_combout\);

-- Location: LCCOMB_X33_Y11_N28
\u2|Mux18~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux18~0_combout\ = (!\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\ & \u1|REGL\(0))) # 
-- (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & ((\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\) # (\u1|REGL\(0))))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000011010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\,
	combout => \u2|Mux18~0_combout\);

-- Location: LCCOMB_X33_Y8_N26
\u2|Selector8~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector8~0_combout\ = (\u2|Mux10~0_combout\ & ((\u2|cs.st1~q\) # ((\u2|cs.st2~q\ & \u2|Mux18~0_combout\)))) # (!\u2|Mux10~0_combout\ & (\u2|cs.st2~q\ & (\u2|Mux18~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110101011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mux10~0_combout\,
	datab => \u2|cs.st2~q\,
	datac => \u2|Mux18~0_combout\,
	datad => \u2|cs.st1~q\,
	combout => \u2|Selector8~0_combout\);

-- Location: LCCOMB_X33_Y8_N12
\u2|Mux2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux2~0_combout\ = (!\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & ((\u1|REGL\(0)) # (!\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & (\u1|REGL\(0) & !\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000000110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	combout => \u2|Mux2~0_combout\);

-- Location: LCCOMB_X33_Y8_N20
\u2|Selector8~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector8~1_combout\ = (\u2|Selector8~0_combout\) # ((!\u2|cs.st0~q\ & \u2|Mux2~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|cs.st0~q\,
	datac => \u2|Selector8~0_combout\,
	datad => \u2|Mux2~0_combout\,
	combout => \u2|Selector8~1_combout\);

-- Location: LCCOMB_X33_Y8_N28
\u2|Mux1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux1~0_combout\ = (\u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\) # ((\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & ((!\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\) # (!\u1|REGL\(0)))) # 
-- (!\u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\ & ((\u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101111111101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod0|auto_generated|divider|divider|StageOut[57]~86_combout\,
	datab => \u2|Mod0|auto_generated|divider|divider|StageOut[59]~88_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod0|auto_generated|divider|divider|StageOut[58]~87_combout\,
	combout => \u2|Mux1~0_combout\);

-- Location: LCCOMB_X33_Y11_N6
\u2|Mux17~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux17~0_combout\ = (\u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\) # ((\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & ((!\u1|REGL\(0)) # (!\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\))) # 
-- (!\u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\ & (\u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111101101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod1|auto_generated|divider|divider|StageOut[58]~23_combout\,
	datab => \u2|Mod1|auto_generated|divider|divider|StageOut[57]~22_combout\,
	datac => \u1|REGL\(0),
	datad => \u2|Mod1|auto_generated|divider|divider|StageOut[59]~24_combout\,
	combout => \u2|Mux17~0_combout\);

-- Location: LCCOMB_X32_Y11_N28
\u2|Mux9~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Mux9~0_combout\ = (\u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\) # ((\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & ((!\u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\) # 
-- (!\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\))) # (!\u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\ & (\u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111011011111110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|Mod2|auto_generated|divider|divider|StageOut[13]~1_combout\,
	datab => \u2|Mod2|auto_generated|divider|divider|StageOut[14]~2_combout\,
	datac => \u2|Mod2|auto_generated|divider|divider|StageOut[15]~3_combout\,
	datad => \u2|Mod2|auto_generated|divider|divider|StageOut[12]~0_combout\,
	combout => \u2|Mux9~0_combout\);

-- Location: LCCOMB_X33_Y8_N30
\u2|Selector7~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector7~0_combout\ = (\u2|cs.st1~q\ & (((!\u2|Mux17~0_combout\ & \u2|cs.st2~q\)) # (!\u2|Mux9~0_combout\))) # (!\u2|cs.st1~q\ & (!\u2|Mux17~0_combout\ & (\u2|cs.st2~q\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000010111010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \u2|cs.st1~q\,
	datab => \u2|Mux17~0_combout\,
	datac => \u2|cs.st2~q\,
	datad => \u2|Mux9~0_combout\,
	combout => \u2|Selector7~0_combout\);

-- Location: LCCOMB_X33_Y8_N6
\u2|Selector7~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \u2|Selector7~1_combout\ = (\u2|Selector7~0_combout\) # ((!\u2|Mux1~0_combout\ & !\u2|cs.st0~q\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111100000011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \u2|Mux1~0_combout\,
	datac => \u2|cs.st0~q\,
	datad => \u2|Selector7~0_combout\,
	combout => \u2|Selector7~1_combout\);

ww_ALE0 <= \ALE0~output_o\;

ww_START0 <= \START0~output_o\;

ww_OE0 <= \OE0~output_o\;

ww_ADDA0 <= \ADDA0~output_o\;

ww_WEI0(0) <= \WEI0[0]~output_o\;

ww_WEI0(1) <= \WEI0[1]~output_o\;

ww_WEI0(2) <= \WEI0[2]~output_o\;

ww_WEI0(3) <= \WEI0[3]~output_o\;

ww_WEI0(4) <= \WEI0[4]~output_o\;

ww_WEI0(5) <= \WEI0[5]~output_o\;

ww_DUAN0(0) <= \DUAN0[0]~output_o\;

ww_DUAN0(1) <= \DUAN0[1]~output_o\;

ww_DUAN0(2) <= \DUAN0[2]~output_o\;

ww_DUAN0(3) <= \DUAN0[3]~output_o\;

ww_DUAN0(4) <= \DUAN0[4]~output_o\;

ww_DUAN0(5) <= \DUAN0[5]~output_o\;

ww_DUAN0(6) <= \DUAN0[6]~output_o\;

ww_DUAN0(7) <= \DUAN0[7]~output_o\;
END structure;



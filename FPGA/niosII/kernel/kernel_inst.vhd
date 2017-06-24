	component kernel is
		port (
			clk_clk       : in    std_logic                     := 'X';             -- clk
			reset_reset_n : in    std_logic                     := 'X';             -- reset_n
			sdram_addr    : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_ba      : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_cas_n   : out   std_logic;                                        -- cas_n
			sdram_cke     : out   std_logic;                                        -- cke
			sdram_cs_n    : out   std_logic;                                        -- cs_n
			sdram_dq      : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_dqm     : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_ras_n   : out   std_logic;                                        -- ras_n
			sdram_we_n    : out   std_logic                                         -- we_n
		);
	end component kernel;

	u0 : component kernel
		port map (
			clk_clk       => CONNECTED_TO_clk_clk,       --   clk.clk
			reset_reset_n => CONNECTED_TO_reset_reset_n, -- reset.reset_n
			sdram_addr    => CONNECTED_TO_sdram_addr,    -- sdram.addr
			sdram_ba      => CONNECTED_TO_sdram_ba,      --      .ba
			sdram_cas_n   => CONNECTED_TO_sdram_cas_n,   --      .cas_n
			sdram_cke     => CONNECTED_TO_sdram_cke,     --      .cke
			sdram_cs_n    => CONNECTED_TO_sdram_cs_n,    --      .cs_n
			sdram_dq      => CONNECTED_TO_sdram_dq,      --      .dq
			sdram_dqm     => CONNECTED_TO_sdram_dqm,     --      .dqm
			sdram_ras_n   => CONNECTED_TO_sdram_ras_n,   --      .ras_n
			sdram_we_n    => CONNECTED_TO_sdram_we_n     --      .we_n
		);


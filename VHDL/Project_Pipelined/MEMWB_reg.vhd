library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MEMWB_reg is
    Port (clk           : in  std_logic;
        rst           : in  std_logic;  -- synchronous reset, active high

        -- Control signal groups from the ID stage:
        WB_in         : in  std_logic_vector(1 downto 0);  -- e.g. {RegWrite, MemtoReg}

        -- Data signals coming from the ID stage:
		  data_mem_in : in  std_logic_vector(31 downto 0);
		  ALU_result_in : in  std_logic_vector(31 downto 0);
        rd_in         : in  std_logic_vector(4 downto 0);
       
        -- Pipeline outputs for control signals:
        WB_out        : out std_logic_vector(1 downto 0);

        -- Pipeline outputs for data signals:
        data_mem_out: out std_logic_vector(31 downto 0);
		  ALU_result_out : out std_logic_vector(31 downto 0);
        rd_out        : out std_logic_vector(4 downto 0));
end MEMWB_reg;

architecture Behavioral of MEMWB_reg is
begin
    process(clk)
    begin
        if rst = '1' then
            WB_out         <= (others => '0');
				data_mem_out <= (others => '0');
				ALU_result_out <= (others => '0');
            rd_out         <= (others => '0');
        elsif rising_edge(clk) then
            -- Latch the control signals:
            WB_out         <= WB_in;
            
            -- Latch the data signals:
				data_mem_out <= data_mem_in;
            ALU_result_out <= ALU_result_in;
            rd_out         <= rd_in;
        end if;
    end process;
end Behavioral;
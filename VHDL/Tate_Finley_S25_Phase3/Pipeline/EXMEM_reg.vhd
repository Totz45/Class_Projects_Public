library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity EXMEM_reg is
    Port (clk           : in  std_logic;
        rst           : in  std_logic;  -- synchronous reset, active high

        -- Control signal groups from the ID stage:
        WB_in         : in  std_logic_vector(1 downto 0);  -- e.g. {RegWrite, MemtoReg}
        MEM_in        : in  std_logic_vector(2 downto 0);  -- e.g. {Branch, Mem_Read, Mem_Write}

        -- Data signals coming from the ID stage:
		  pc_in         : in  std_logic_vector(31 downto 0);
        Zero_reg_in   : in  std_logic;
		  ALU_result_in : in  std_logic_vector(31 downto 0);
        read_data2_in : in  std_logic_vector(31 downto 0);
        rd_in         : in  std_logic_vector(4 downto 0);
       

        -- Pipeline outputs for control signals:
        WB_out        : out std_logic_vector(1 downto 0);
        MEM_out       : out std_logic_vector(2 downto 0);

        -- Pipeline outputs for data signals:
		  pc_out        : out std_logic_vector(31 downto 0);
		  Zero_reg_out  : out std_logic;
        ALU_result_out : out std_logic_vector(31 downto 0);
        read_data2_out: out std_logic_vector(31 downto 0);
        rd_out        : out std_logic_vector(4 downto 0));
end EXMEM_reg;

architecture Behavioral of EXMEM_reg is
begin
    process(clk)
    begin
        if rst = '1' then
            WB_out         <= (others => '0');
            MEM_out        <= (others => '0');
				pc_out         <= (others => '0');
            Zero_reg_out   <= '0';
				ALU_result_out <= (others => '0');
            read_data2_out <= (others => '0');
            rd_out         <= (others => '0');
        elsif rising_edge(clk) then
            -- Latch the control signals:
            WB_out         <= WB_in;
            MEM_out        <= MEM_in;
            
            -- Latch the data signals:
				pc_out         <= pc_in;
				Zero_reg_out   <= Zero_reg_in;
            ALU_result_out <= ALU_result_in;
            read_data2_out <= read_data2_in;
            rd_out         <= rd_in;
        end if;
    end process;
end Behavioral;
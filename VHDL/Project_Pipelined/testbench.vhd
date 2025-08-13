-- File Name: testbench.vhd
-- Author: Tate Finley
-- Purpose: Test the performance of some MIPs instructions through the MIPs processor.

library ieee;
use ieee.std_logic_1164.all;

entity testbench is
end testbench;

architecture behavioral of testbench is

    -- Component declaration for the top-level Computer entity.
    component Computer 
	 port( D:					IN STD_LOGIC_VECTOR(31 downto 0);
			address:			IN STD_LOGIC_VECTOR(7 downto 0);
			clock, reset, reg_reset: 	IN STD_LOGIC;
			wren: 			IN STD_LOGIC;
			Instr, Reg_out1, Reg_out2: 				OUT STD_LOGIC_VECTOR(31 downto 0);
			ALU_o, data_mem, Q: 				OUT STD_LOGIC_VECTOR(31 downto 0));
	 end component;
    
    -- Signal declarations.
    signal address       : std_logic_vector(7 downto 0) := "00000000";
    signal instr_data    : std_logic_vector(31 downto 0) := x"00000000"; --input into instruction memory
    signal wren_sig      : std_logic := '0';
    signal reset_sig     : std_logic := '0';
    signal reg_reset     : std_logic := '0'; -- reset PC if needed 
	 signal clock_sig     : std_logic := '0';
	 signal IF_instr_out     : std_logic_vector(31 downto 0) := x"00000000"; --instruction sent to register unit
    signal ID_ALU_out1, ID_ALU_out2      : std_logic_vector(31 downto 0) := x"00000000";
	 signal EX_ALU_outTotal       : std_logic_vector(31 downto 0) := x"00000000";
    signal MEM_dataMem_o, WB_dataMem_Q        : std_logic_vector(31 downto 0) := x"00000000";
	 
begin
    
    DUT: Computer port map(
            D            => instr_data,
            address      => address,
            clock        => clock_sig,
            reset        => reset_sig,
            reg_reset    => reg_reset,
            wren         => wren_sig,
            Instr        => IF_instr_out,
				Reg_out1     => ID_ALU_out1,
				Reg_out2     => ID_ALU_out2,
				ALU_o        => EX_ALU_outTotal,
				data_mem     => MEM_dataMem_o,
            Q            => WB_dataMem_Q
         );
    
    
    clock_sig <= not clock_sig after 50 ns;
    
	 
	 -- phase 1 setup for testbench
	 
    reset_sig <= '0', 
                 '1' after 25 ns, 
                 '0' after 175 ns; 
    
	 reg_reset <= '0';
    
    address <= "00000000";
    
    wren_sig <= '0', 
                '1' after 26 ns, 
                '0' after 1175 ns;
    
   instr_data <= x"00000000",            -- Initial default value
                  
						-- Register Loading Phase:
                  X"20090006" after 225 ns, -- t1 loaded with value 6
						X"200A0005" after 325 ns, -- t2 loaded with value 5
						X"200B000A" after 425 ns, -- t3 loaded with value 10
						X"200C000C" after 525 ns, -- t4 loaded with value 12
                  
						-- Instruction Execution Phase:
                  x"112A0010" after 725 ns,  -- (a) beq  $t1, $t2, Equal 
                  x"012A4820" after 825 ns, -- (b) add $t1, $t1, $t2
                  x"AD4B0064" after 925 ns, -- (c) sw $t3, 100($t2)
                  x"018A4825" after 1025 ns, -- (d) or $t1, $t4, $t2
                  x"00000000" after 1125 ns; -- (e) Equal: .. 

end behavioral;

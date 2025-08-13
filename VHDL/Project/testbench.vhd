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
			Instr, ALU_o, dataMem: 				OUT STD_LOGIC_VECTOR(31 downto 0);
			Q: 				OUT STD_LOGIC_VECTOR(31 downto 0));
	 end component;
    
    -- Signal declarations.
    signal address       : std_logic_vector(7 downto 0) := "00000000";
    signal clock_sig     : std_logic := '0';
    signal instr_data    : std_logic_vector(31 downto 0) := x"00000000"; --input into instruction memory
    signal wren_sig      : std_logic := '0';
    signal instr_out     : std_logic_vector(31 downto 0) := x"00000000"; --instruction sent to register unit
    signal ALU_out       : std_logic_vector(31 downto 0) := x"00000000";
    signal reset_sig     : std_logic := '0';
    signal reg_reset     : std_logic := '0'; -- reset PC if needed
	 signal dataMem_o        : std_logic_vector(31 downto 0) := x"00000000";
    signal Q_o        : std_logic_vector(31 downto 0) := x"00000000";
begin
    
    DUT: Computer port map(
            D            => instr_data,
            address      => address,
            clock        => clock_sig,
            reset        => reset_sig,
            reg_reset    => reg_reset,
            wren         => wren_sig,
            Instr        => instr_out,
				ALU_o        => ALU_out,
				dataMem      => dataMem_o,
            Q            => Q_o
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
                '0' after 1075 ns;
    
   instr_data <= x"00000000",            -- Initial default value
                  
						-- Register Loading Phase:
                  X"20090005" after 225 ns, -- t1 loaded with value 5
						X"200A0006" after 325 ns, -- t2 loaded with value 6
						X"200B0001" after 425 ns, -- t3 loaded with value 1
						X"200C000C" after 525 ns, -- t4 loaded with value 12
                  
						-- Instruction Execution Phase:
                  x"112A0010" after 625 ns,  -- (a) beq  $t1, $t2, Equal 
                  x"012A4820" after 725 ns, -- (b) add $t1, $t1, $t2
                  x"AD4B0064" after 825 ns, -- (c) sw $t3, 100($t2)
                  x"018A4825" after 925 ns, -- (d) or $t1, $t4, $t2
                  x"00000000" after 1025 ns; -- (e) Equal: .. 

end behavioral;

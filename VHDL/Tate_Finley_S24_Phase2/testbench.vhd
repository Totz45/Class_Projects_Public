-- File Name: testbench.vhd
-- Author: Tate Finley
-- Purpose: Test the performance of some MIPs instructions through the MIPs processor.

library ieee;
use ieee.std_logic_1164.all;

entity testbench is
end testbench;

architecture behavioral of testbench is

    -- Component declaration for the top-level Computer entity.
    component Computer is 
        port(
            D            : in  std_logic_vector(31 downto 0);
            address      : in  std_logic_vector(7 downto 0);
            clock, reset, reg_reset : in  std_logic;
            wren         : in  std_logic;
            RegWrite, ALUsrc, RegDst : in  std_logic;
            ALU_operation: in  std_logic_vector(3 downto 0);
            Instr, Q     : out std_logic_vector(31 downto 0)
        );
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
    signal RegWrite_sig  : std_logic := '1'; 
    signal ALUsrc_sig    : std_logic := '0'; -- select line for ALU mux
    signal RegDst_sig    : std_logic := '1'; -- select line for write register input mux
    signal ALU_op        : std_logic_vector(3 downto 0) := "0000";

begin
    
    DUT: Computer port map(
            D            => instr_data,
            address      => address,
            clock        => clock_sig,
            reset        => reset_sig,
            reg_reset    => reg_reset,
            wren         => wren_sig,
            RegWrite     => RegWrite_sig,
            ALUsrc       => ALUsrc_sig,
            RegDst       => RegDst_sig,
            ALU_operation=> ALU_op,
            Instr        => instr_out,
            Q            => ALU_out
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
                '0' after 1375 ns;
    
    -- Phase 2 control signals
    
	 ALUsrc_sig <= '1', '0' after 950 ns, '1' after 1450 ns;
    RegDst_sig <= '0', '1' after 950 ns, '0' after 1450 ns;
    
    
    ALU_op <= "0010",               -- default 
              "0010" after 950 ns,  -- (a) add $t3, $t0, $t1 
              "0110" after 1050 ns,  -- (b) sub $t4, $s0, $s1 
              "0000" after 1150 ns,  -- (c) and $t5, $t3, $t4 
              "0111" after 1250 ns,  -- (d) xor $t0, $s3, $s4 
              "1100" after 1350 ns,  -- (e) nor (used for NOT $t6)
              "0010" after 1450 ns;  -- (f) addi $s3, $s3, 4
    
    
	 
    instr_data <= x"00000000",            -- Initial default value
                  
						-- Register Loading Phase:
                  X"2008000A" after 125 ns, -- t0 loaded with value 10
						X"20090014" after 225 ns, -- t1 loaded with value 20
						X"20100028" after 325 ns, -- s0 loaded with value 40
						X"2011000F" after 425 ns, -- s1 loaded with value 15
						X"20130021" after 525 ns, -- s3 loaded with value 33
						X"20140016" after 625 ns, -- s4 loaded with value 22
						X"200E0032" after 725 ns, -- t6 loaded with value 50
                  
						-- Instruction Execution Phase:
                  x"01095820" after 825 ns,  -- (a) add  $t3, $t0, $t1 (R11 = R8 + R9)
                  x"02116022" after 925 ns, -- (b) sub  $t4, $s0, $s1 (R12 = R16 - R17)
                  x"016C6824" after 1025 ns, -- (c) and  $t5, $t3, $t4 (R13 = R11 AND R12)
                  x"02744026" after 1125 ns, -- (d) xor  $t0, $s3, $s4 (R8 = R19 XOR R20)
                  x"01C07027" after 1225 ns, -- (e) nor  $t6, $t6, $zero (R14 = NOT R14)
                  x"22730004" after 1325 ns; -- (f) addi $s3, $s3, 4 (R19 = R19 + 4)

end behavioral;

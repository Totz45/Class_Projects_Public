----------------------------------------
-- Tate Finley 
-- ECE 3140
-- HW3 Problem 7
-- 
-- Testbench for implementation of
-- problem 4.9
----------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;
----------------------------------------  
--Description
----------------------------------------  
entity testbench is
end entity testbench;

architecture BENCH of testbench is
  
  component hw3p49 is port(
  	in3: in std_logic;
  	in2: in std_logic;
  	in1: in std_logic;
  	in0: in std_logic;
  	out_49A: out std_logic;
  	out_49B: out std_logic;
  	out_49C: out std_logic;
    out_49D: out std_logic;
  	out_49E: out std_logic;
  	out_49F: out std_logic;
  	out_49G: out std_logic);  
  end component;
  
  signal A : std_logic_vector(3 downto 0);
  signal OUT_A, OUT_B, OUT_C, OUT_D, OUT_E, OUT_F, OUT_G : std_logic;

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: hw3p49 port map (A(3),A(2),A(1),A(0),OUT_A,OUT_B,OUT_C,OUT_D,OUT_E,OUT_F,OUT_G);

  stimulus : process
    begin
      report "Test for Problem 4.9" severity NOTE;
      A <= "0000";
      wait for 20 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "0001";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "0010";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "0011";
      wait for 10 ns;
	  assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
	  A <= "0100";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "0101";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "0110";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "0111";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
	  A <= "1000";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "1001";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "1010";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "1011";
      wait for 10 ns;
	  assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;

	  A <= "1100";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "1101";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "1110";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "1111";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;

      A <= "0000";
      wait for 10ns;

      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

----------------------------------------
-- Tate Finley 
-- ECE 3140
-- HW3 Problem 7
-- 
-- Testbench for implementation of
-- problem 4.4
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
  
  component hw3p44 is port(
   	in2: in std_logic;
  	in1: in std_logic;
  	in0: in std_logic;
  	out_44A: out std_logic;
  	out_44B: out std_logic);  
  end component;
  
  signal A : std_logic_vector(2 downto 0);
  signal OUT_F, OUT_G : std_logic;

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: hw3p44 port map (A(2),A(1),A(0),OUT_F,OUT_G);

  stimulus : process
    begin
      report "Test for Problem 4.4" severity NOTE;
      A <= "000";
      wait for 20 ns;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "001";
      wait for 10 ns;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "010";
      wait for 10 ns;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "011";
      wait for 10 ns;
	  assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
	  A <= "100";
      wait for 10 ns;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "101";
      wait for 10 ns;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      
      A <= "110";
      wait for 10 ns;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      
      A <= "111";
      wait for 10 ns;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      

      A <= "000";
      wait for 10ns;

      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

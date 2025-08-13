----------------------------------------
-- Tate Finley 
-- ECE 3140
-- HW4 Problem 5
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
  
  component hw5p3 is 
	port( Clock, SetState: in std_logic;
			o_LFSR : out std_logic_vector(4 downto 0));
  end component;
  
  signal checkLFSR : std_logic;
  signal Set : std_logic;
  signal OUT_LFSR : std_logic_vector(4 downto 0);
  signal CLK : std_logic := '0';
  constant Clock_period : time := 20 ns;
  

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: hw5p3 port map (Clock=>CLK,SetState=>Set,o_LFSR=>OUT_LFSR);
  
  --checking the Lsb of LFSR which has a period of 7
  checkLFSR <= OUT_LFSR(0);
	
  clock_p : process
  begin
	CLK <= '0';
        wait for Clock_period/2;
        CLK <= '1';
        wait for Clock_period/2;
  end process;
  stimulus : process
    begin
      report "Test for Homework 5 Problem 3" severity NOTE;
      Set <= '1';
      wait for 15 ns;
      --Checking for state 000
      Set <= '0';
      wait for 10 ns;
      assert (checkLFSR = '0') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 001
      wait for 20 ns;
      assert (checkLFSR = '1') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 011
      wait for 20 ns;
      assert (checkLFSR = '1') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 110
      wait for 20 ns;
      assert (checkLFSR = '0') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --checking for state 101
      wait for 20 ns;
      assert (checkLFSR = '1') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 010
      wait for 20 ns;
      assert (checkLFSR = '0') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 100
      wait for 20 ns;
      assert (checkLFSR = '0') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --Checking for state 000
      wait for 20 ns;
      assert (checkLFSR = '0') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --checking for repeat sequence so 001
      wait for 20 ns;
      assert (checkLFSR = '1') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --testing repeat again
      wait for 20 ns;
      assert (checkLFSR = '1') report "Test Failed, Function LFSR Lsb" severity ERROR;
      --check for Set to 000
      Set <= '1';
      wait for 10 ns;
      assert (checkLFSR = '0') report "Test Failed, Function Set" severity ERROR;
      --check for Set after 1 CLK cycle
      wait for 20 ns;
      assert (checkLFSR = '0') report "Test Failed, Function Set after CLK" severity ERROR;
      Set <= '0';
      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

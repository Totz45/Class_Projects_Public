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
  
  component hw5p2 is port(
  	SW0: in STD_LOGIC;
  	SW9: in STD_LOGIC;
  	SW1: in STD_LOGIC;
  	HEX5: out STD_LOGIC_VECTOR(7 downto 0);
  	LEDR0: out STD_LOGIC);  
  end component;

  signal FSM_input, Reset : std_logic;
  signal OUT_LED : std_logic;
  signal OUT_sevSeg : std_logic_vector(7 downto 0);
  signal Clock : std_logic := '0';
  constant Clock_period : time := 20 ns;

  

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: hw5p2 port map (SW0=>FSM_input,SW9=>Clock,SW1=>Reset,HEX5=>OUT_sevSeg,LEDR0=>OUT_LED);

 	
  clock_p : process
  begin
	Clock <= '0';
        wait for Clock_period/2;
        Clock <= '1';
        wait for Clock_period/2;
  end process;
  stimulus : process
    begin
      report "Test for Homework 5 Problem 2" severity NOTE;
      Reset <= '1';
      FSM_input <= '0';
      wait for 15 ns;
      assert (OUT_sevseg = "10001000") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='1') report "Test Failed, Function LED" severity ERROR;
      Reset <= '0';
      wait for 20 ns;
      assert (OUT_sevseg = "10000011") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      wait for 20 ns;
      assert (OUT_sevseg = "11000110") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      FSM_input <= '1';
      wait for 20 ns;
      assert (OUT_sevseg = "10100001") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      wait for 20 ns;
      assert (OUT_sevseg = "10001000") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      wait for 20 ns;
      assert (OUT_sevseg = "11000110") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='1') report "Test Failed, Function LED" severity ERROR;
      FSM_input <= '0';
      wait for 20 ns;
      assert (OUT_sevseg = "10000011") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      FSM_input <= '1';
      wait for 10 ns;
      assert (OUT_sevseg = "10000011") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='1') report "Test Failed, Function LED" severity ERROR;
      wait for 10 ns;
      assert (OUT_sevseg = "10100001") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      FSM_input <= '0';
      wait for 10 ns;
      assert (OUT_sevseg = "10100001") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='1') report "Test Failed, Function LED" severity ERROR;
      wait for 10 ns;
      assert (OUT_sevseg = "11000110") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='0') report "Test Failed, Function LED" severity ERROR;
      Reset <= '1';
      FSM_input <= '0';
      wait for 20 ns;
      assert (OUT_sevseg = "10001000") report "Test Failed, Function seven Segment" severity ERROR;
      assert (OUT_LED='1') report "Test Failed, Function LED" severity ERROR;
      Reset <= '0';
      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

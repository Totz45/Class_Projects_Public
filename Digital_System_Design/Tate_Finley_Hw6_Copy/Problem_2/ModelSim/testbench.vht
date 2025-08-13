----------------------------------------
-- Tate Finley 
-- ECE 3140
-- HW6 Problem 2
-- 
-- Testbench for implementation of
-- hw6p2
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
  
  --using equivalent structure of hw6p2 to generate 16Mhz clock
  component ripple_counter is
 	generic (n : natural := 4);
 	port ( clk : in std_logic;
        	clear : in std_logic;
        	dout : out std_logic_vector(n-1 downto 0));
  end component;
  
  signal reset_value : std_logic_vector(23 downto 0) := (others => '0');
  signal counter : std_logic_vector(23 downto 0) := (others => '0');
  signal Switch : std_logic_vector(9 downto 0);
  signal Buzzer, LEDR0 : std_logic := '0';
  signal reset : std_logic := '1';
  signal Clock_16Mhz : std_logic := '0';
  constant Clock_period : time := 60 ns;
  constant Num_Bits : integer := 24;
  

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: ripple_counter generic map (n => Num_Bits) 
	port map(clk => Clock_16Mhz, clear => reset, dout => counter); 
  
  --had to rewrite hw6p2 in testbench to have generating clock work.

  --equivalent pll clock function	
  clock_generate : process
  begin
	Clock_16Mhz <= '0';
        wait for Clock_period/2;
        Clock_16Mhz <= '1';
        wait for Clock_period/2;
  end process;
  
  -- rest of hw6p2
  reset_vector: process(Switch)
  begin
	reset_value(23) <= Switch(9);
	reset_value(22) <= Switch(8);
	reset_value(21) <= Switch(7);
	reset_value(20) <= Switch(6);
	reset_value(19) <= Switch(5);
	reset_value(18) <= Switch(4);
	reset_value(17) <= Switch(3);
	reset_value(16) <= Switch(2);
	reset_value(15) <= Switch(1);
	reset_value(14) <= Switch(0);
  end process;
	
  reset_counter: process(counter, reset_value, Buzzer, LEDR0)
  begin
	if(counter = reset_value or counter > reset_value) then
		reset <= '1';
		Buzzer <= not Buzzer;
		LEDR0 <= not LEDR0;
	else
		reset <= '0';
	end if;
  end process;

  --begin testbench

  stimulus : process
    begin
      report "Test for Homework 6 Problem 2" severity NOTE;
      --test period for given switches
      --ignored most significant 3 bits in switch otherwise simulation goes for too long
      --equivalent period is 2^n ms for each bit where n is the place of the bit 
      --looking from right to left Lsb=> n=1 Msb=> n=10.
      Switch <= "0001000000";
      wait for 1 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 63 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 1 ms;
      
      Switch <= "0000100000";
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 32 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      
      --period is approximately 32 ms here so both outputs toggle every 16 ms
      Switch <= "0000010000";
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 16 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
     
      Switch <= "0000001000";
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 8 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      
      Switch <= "0000000100";
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 4 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 1 ms;

      --testing the entire period for second switch enabled
      Switch <= "0000000010";
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 2.1 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 2 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 1 ms;
      

      Switch <= "0000000001";
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 0.5 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 1 ms;

      --testing the period for a combination of switches calculated to be 20 ms
      Switch <= "0000001010";
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 4 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      wait for 8 ms;
      assert (Buzzer= '0') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '0') report "Test Failed, Function LED 0" severity ERROR;
      wait for 10 ms;
      assert (Buzzer= '1') report "Test Failed, Function Buzzer" severity ERROR;
      assert (LEDR0= '1') report "Test Failed, Function LED 0" severity ERROR;
      
      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

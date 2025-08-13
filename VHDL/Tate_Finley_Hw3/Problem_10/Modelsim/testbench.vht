-- Tate Finley
-- ECE 3140
-- Hw3 Problem 10

-- THE EXAMPLE IS DIRECTLY BELOW
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

entity testbench is
end entity testbench;

architecture BENCH of testbench is
  
  component hw3p8 is 
  port(in_a: in STD_LOGIC;
  	   in_b: in STD_LOGIC;
       in_c: in STD_LOGIC;
       out_f: out STD_LOGIC); 
  end component;
  
  signal A : STD_LOGIC_VECTOR(2 downto 0);
  signal p8 : STD_LOGIC;

  begin
  
  -- instantiate our "device under test" (DUT)	
  DUT0: hw3p8 port map (A(2),A(1),A(0),p8);
  
  stimulus : process
    begin
      A <= "000";
      wait for 20ns;
      A <= "001";
      wait for 10ns;
      A <= "010";
      wait for 10ns;
      A <= "011";
      wait for 10ns;

	  A <= "100";
      wait for 10ns;
      A <= "101";
      wait for 10ns;
      A <= "110";
      wait for 10ns;
      A <= "111";
      wait for 10ns;

	--testing transitions 001
	  A <= "001";
      wait for 10ns;
      A <= "101";
      wait for 10ns;
      
      A <= "001";
      wait for 10ns;
      A <= "110";
      wait for 10ns;

	  A <= "001";
      wait for 10ns;
      A <= "111";
      wait for 10ns;
      
     --testing transitions 101 
      A <= "101";
      wait for 10ns;
      A <= "001";
      wait for 10ns;

      A <= "101";
      wait for 10ns;
      A <= "110";
      wait for 10ns;
      
      A <= "101";
      wait for 10ns;
      A <= "111";
      wait for 10ns;
     
     --testing transitions 110 
      A <= "110";
      wait for 10ns;
      A <= "001";
      wait for 10ns;
      
      A <= "110";
      wait for 10ns;
      A <= "101";
      wait for 10ns;
      
      A <= "110";
      wait for 10ns;
      A <= "111";
      wait for 10ns;
     
     --testing transitions 111
      A <= "111";
      wait for 10ns;
      A <= "001";
      wait for 10ns;
      
      A <= "111";
      wait for 10ns;
      A <= "101";
      wait for 10ns;
      
      A <= "111";
      wait for 10ns;
      A <= "110";
      wait for 10ns;
      
      A <= "000";
      wait for 10ns;

	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  
  
  
end architecture BENCH;

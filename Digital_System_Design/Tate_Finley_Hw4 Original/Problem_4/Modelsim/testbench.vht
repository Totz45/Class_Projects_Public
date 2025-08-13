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
  
  component bin2seg7 is port(
  	inData: in STD_LOGIC_VECTOR(3 downto 0);
	blanking: in STD_LOGIC;
	dispHex, dispPoint: in STD_LOGIC;
	segA, segB, segC, segD: out STD_LOGIC;
	segE, segF, segG: out STD_LOGIC;
	segPoint: out STD_LOGIC); 
  end component;
  
  signal A : std_logic_vector(3 downto 0);
  signal blank, hexValue, point : std_logic;
  signal OUT_A, OUT_B, OUT_C, OUT_D, OUT_E, OUT_F, OUT_G, OUT_Point : std_logic;

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: bin2seg7 port map (A,blank,hexValue,point,OUT_A,OUT_B,OUT_C,OUT_D,OUT_E,OUT_F,OUT_G,OUT_Point);

  stimulus : process
    begin
      report "Test for Problem 4" severity NOTE;
      A <= "0000";
      blank <= '1';
      hexValue <= '1';
      point <= '0';
      wait for 20 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;   

      A <= "0001";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      -- testing blank input
      blank <= '0';
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      -- blank still on
      point <= '1';
      A <= "0010";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      blank <= '1';
      point <= '0';
      wait for 10 ns;
      --resume logic
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "0011";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "0100";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      --testing point
      point <= '1';
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='0') report "Test Failed, Function Point" severity ERROR;

      A <= "0101";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='0') report "Test Failed, Function Point" severity ERROR;
      -- revert point
      point <= '0';
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;

      A <= "0110";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "0111";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "1000";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;      

      A <= "1001";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      --testing hexValue
      hexValue <= '0';
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "1010";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      blank <= '0';
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      blank <= '1';
      point <= '1';
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='1') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='0') report "Test Failed, Function Point" severity ERROR;
      
      --resume normal logic
      point <= '0';
      hexValue <= '1';
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;
      
      A <= "1011";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;

      A <= "1100";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='1') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;      

      A <= "1101";
      wait for 10 ns;
      assert (OUT_A='1') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='0') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='0') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='1') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;      

      A <= "1110";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='0') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;      

      A <= "1111";
      wait for 10 ns;
      assert (OUT_A='0') report "Test Failed, Function A" severity ERROR;
      assert (OUT_B='1') report "Test Failed, Function B" severity ERROR;
      assert (OUT_C='1') report "Test Failed, Function C" severity ERROR;
      assert (OUT_D='1') report "Test Failed, Function D" severity ERROR;
      assert (OUT_E='0') report "Test Failed, Function E" severity ERROR;
      assert (OUT_F='0') report "Test Failed, Function F" severity ERROR;
      assert (OUT_G='0') report "Test Failed, Function G" severity ERROR;
      assert (OUT_Point='1') report "Test Failed, Function Point" severity ERROR;

      A <= "0000";
      wait for 10ns;

      report "Test Success" severity NOTE;
	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;

  

end architecture BENCH;

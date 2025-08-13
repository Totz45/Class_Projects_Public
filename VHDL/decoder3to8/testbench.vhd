-- THE EXAMPLE IS DIRECTLY BELOW
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.NUMERIC_STD.all;

----------------------------------------  
entity testbench is
end entity testbench;

architecture BENCH of testbench is
  signal A : STD_LOGIC_VECTOR(2 downto 0);
  signal X : STD_LOGIC_VECTOR(7 downto 0);

  component decoder3to8
  port ( sel : in STD_LOGIC_VECTOR (2 downto 0);
    		y  : out STD_LOGIC_VECTOR (7 downto 0));
  end component;
	
  begin
	--instantiate our "device under test" (DUT)
  UUT: decoder3to8 port map (sel => A, y => X);
  
  stimulus: process
    begin
      A <= "000";
      wait for 20 ns;
      A <= "001";
      wait for 10 ns;
      A <= "010";
      wait for 10 ns;
      A <= "011";
      wait for 10 ns;

	  A <= "100";
      wait for 10 ns;
      A <= "101";
      wait for 10 ns;
      A <= "110";
      wait for 10 ns;
      A <= "111";
      wait for 10 ns;

      A <= "000";
      wait for 10ns;

	  -- your test bench must always finish with a "wait;" command or
      --    the sim will try to run forever
      wait;					
   end process stimulus;
   
end architecture BENCH;
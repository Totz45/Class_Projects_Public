----------------------------------------
-- Tate Finley 
-- ECE 3140
-- HW3 Problem 7
-- 
-- Testbench for implementation of
-- problem 4.2
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
  
  component hw4p1 is port(
	SW: in STD_LOGIC_VECTOR(3 downto 0);
	KEY: in STD_LOGIC_VECTOR(1 downto 0);
	LEDR0: out std_logic;
	LEDR9: out std_logic);
  end component;
  
  signal A : std_logic_vector(3 downto 0);
  Signal Pushbutton : std_logic_vector(1 downto 0);
  signal OUT_F, OUT_G : std_logic;

  begin
  
  -- instantiate our "device under test" (DUT)
  DUT0: hw4p1 port map (A,Pushbutton,OUT_F,OUT_G);

  stimulus : process
    begin
      	report "Test for Problem 1" severity NOTE;
      	Pushbutton <= "11";
      	A <= "0000";
      	wait for 20 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
      	Pushbutton <= "01";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
      	Pushbutton <= "10";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
      	Pushbutton <= "11";
      	A <= "0001";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	
      	Pushbutton <= "11";
      	A <= "0010";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
      	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;

      	Pushbutton <= "11";
      	A <= "0011";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;

	Pushbutton <= "11";
	A <= "0100";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "0101";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "0110";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
     
	Pushbutton <= "11";
      	A <= "0111";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
	A <= "1000";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "1001";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "1010";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
     	
	Pushbutton <= "11";
      	A <= "1011";
      	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;

	Pushbutton <= "11";
	A <= "1100";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "1101";
      	wait for 10 ns;
      	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "1110";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
      
	Pushbutton <= "11";
      	A <= "1111";
      	wait for 10 ns;
      	assert (OUT_F='1') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "01";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='1') report "Test Failed" severity ERROR;
	Pushbutton <= "10";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	Pushbutton <= "00";
	wait for 10 ns;
	assert (OUT_F='0') report "Test Failed" severity ERROR;
      	assert (OUT_G='0') report "Test Failed" severity ERROR;
	

      	A <= "0000";
      	wait for 10ns;

      	report "Test Success" severity NOTE;
	-- your test bench must always finish with a "wait;" command or
      	--    the sim will try to run forever
      	wait;					
   end process stimulus;

  

end architecture BENCH;

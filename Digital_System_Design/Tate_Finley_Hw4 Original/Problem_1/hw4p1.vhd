----------------------------------
-- Tate Finley
-- ECE 3140
-- HW4 Problem 1
--
-- Implementation for problem 4.2, using the DE10-Board
----------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.all;

-- This design implements four switches and
-- two keys for the DE10-Board
-- The design has two output Booleans:
--  out_42A: Result of output f for problem 4.2
--  out_42B: Result of output g for problem 4.2

entity hw4p1 is port(
  SW: in STD_LOGIC_VECTOR(3 downto 0);
  KEY: in STD_LOGIC_VECTOR(1 downto 0);
  LEDR0: out std_logic;
  LEDR9: out std_logic);  
end entity hw4p1;

architecture behavioral of hw4p1 is
	
	signal Switch : STD_LOGIC_VECTOR(3 downto 0);
	signal temp1, temp2 : std_logic;

	component hw3p42 is port(
	   in3: in std_logic;
	   in2: in std_logic;
	   in1: in std_logic;
	   in0: in std_logic;
		out_42A: out std_logic;
		out_42B: out std_logic);  
	end component hw3p42;
	
	begin
	
	---------------------------------
	-- Process for changing inputs
	-- based on Keys or Switches
	---------------------------------
	
	Board: process (SW,KEY)
	begin
		------------------------
		-- key pressed is '0' by manual
		-----------------------
		if ((KEY(1)) = '0') then
		 Switch(0) <= not SW(0);
		 Switch(1) <= not SW(1);
		 Switch(2) <= not SW(2);
		 Switch(3) <= not SW(3);
		else
		 Switch(0) <= SW(0);
		 Switch(1) <= SW(1);
		 Switch(2) <= SW(2);
		 Switch(3) <= SW(3);
		end if;
	end process;
	
	---------------------------------
	-- Structural component for
	-- implementing design
	---------------------------------
	
	DUT0: hw3p42 port map (in3=>Switch(3),in2=>Switch(2),in1=>Switch(1),in0=>Switch(0),out_42A=>temp1,out_42B=>temp2);
	
	---------------------------------
	-- Process for changing outputs
	-- based on keys or switches
	---------------------------------
	
	OFF: process (KEY,temp1,temp2)
	begin
		------------------------
		-- key pressed is '0' by manual
		-----------------------
		if ((KEY(0)) = '0') then
		 LEDR0 <= '0';
		 LEDR9 <= '0';
		else
		 LEDR0 <= temp1;
		 LEDR9 <= temp2;
		end if;
	end process;
	
		
end architecture behavioral;

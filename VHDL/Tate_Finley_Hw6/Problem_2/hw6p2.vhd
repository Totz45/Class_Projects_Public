-------------------------------
--  Tate Finley
--  HW6 Problem 2
-------------------------------

library IEEE;
use IEEE.std_logic_1164.all;

entity hw6p2 is
 port ( CLOCK_50 : in std_logic;
        LEDR0 : buffer std_logic := '0';
		  ARDUINO_IO12 : buffer std_logic := '0';
        SW : in std_logic_vector(9 downto 0)
 );
end hw6p2;

architecture design of hw6p2 is
constant counter_bit : integer := 24;
signal counter : std_logic_vector(23 downto 0);
signal Clock : std_logic;
signal reset_vec : std_logic_vector(23 downto 0) := (others => '0');
signal reset : std_logic;

component pll
	PORT
	(
		inclk0		: IN STD_LOGIC  := '0';
		c0		: OUT STD_LOGIC 
	);
end component;

component ripple_counter is
 generic (n : natural := 4);
 port ( clk : in std_logic;
        clear : in std_logic;
        dout : out std_logic_vector(n-1 downto 0)
 );
end component;

begin
   
	--instantiate components

	pll_inst : pll PORT MAP (inclk0	 => CLOCK_50, c0	 => Clock);

	U0: ripple_counter generic map (n => counter_bit)
			port map (clk => Clock, clear => reset, dout => counter);
	
	--set counter reset value based on switches
	reset_vector: process(SW)
	begin
		reset_vec(23) <= SW(9);
		reset_vec(22) <= SW(8);
		reset_vec(21) <= SW(7);
		reset_vec(20) <= SW(6);
		reset_vec(19) <= SW(5);
		reset_vec(18) <= SW(4);
		reset_vec(17) <= SW(3);
		reset_vec(16) <= SW(2);
		reset_vec(15) <= SW(1);
		reset_vec(14) <= SW(0);
	end process;
	
	--output for buzzer and LEDR0 set when counter reaches reset value
	reset_value: process(counter, reset_vec, ARDUINO_IO12, LEDR0)
	begin
		if(counter = reset_vec or counter > reset_vec) then
			reset <= '1';
			ARDUINO_IO12 <= not ARDUINO_IO12;
			LEDR0 <= not LEDR0;
		else
			reset <= '0';
		end if;
	end process;
	


end design;
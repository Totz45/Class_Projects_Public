library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.ALL;
entity my_UpDownCounter is 
generic ( NumBits : natural := 12);
port (
	clock : in STD_LOGIC;
	reset : in STD_LOGIC;
	direction : in STD_LOGIC;
	Count_out : out STD_LOGIC_VECTOR (NumBits-1 downto 0);
	delay: in time);
end my_UpDownCounter;

architecture arch_UpDown of my_UpDownCounter is
	signal current_count, nxt_count : std_logic_vector(NumBits-1 downto 0);
	begin
	counter_reset: process (clock, reset) begin
		if (reset = '1') then
			current_count <= (others => '0');
		elsif (rising_edge(clock)) then
			current_count <= nxt_count;
		end if;
	end process;
	
	counter_next: process(direction, current_count) begin
		if (direction='0') then 
			nxt_count <= current_count after delay;
		else
			nxt_count <= current_count-1 after delay;
		end if;
	end process;
	Count_out <= current_count;
end arch_UpDown;
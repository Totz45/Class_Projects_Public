library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Datapath is
    generic (dp_width : integer := 32);
    Port ( clock, reset, load, add, shift : in STD_LOGIC;
           multiplicand, multiplier : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
           product : out STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
           start, done : out STD_LOGIC);
end Datapath;

architecture Behavioral of Datapath is
    signal A : STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0); -- Multiplicand Register
    signal Q : STD_LOGIC_VECTOR (dp_width-1 downto 0);  -- Multiplier Register
    signal P : STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0) := (others => '0'); -- Product Register
    signal Z : STD_LOGIC_VECTOR (dp_width-1 downto 0);
	 signal count : integer := 0;
begin
    process (clock, reset)
    begin
        Z <= (others => '0');
		  if reset = '1' then
            A <= (others => '0');
            Q <= (others => '0');
            P <= (others => '0');
            count <= 0;
            start <= '0';
            done <= '0';
        elsif rising_edge(clock) then
            if load = '1' then
                -- Initialize all registers
					 A <= Z & multiplicand;
                Q <= multiplier;
                P <= (others => '0');
                count <= 0; 
                start <= '1';
                done <= '0';
            elsif add = '1' then
                -- Add multiplicand to product if LSB of multiplier is 1, restore register otherwise
					 if Q(0) = '1' then
                    P <= P + A; 
                end if;
            elsif shift = '1' then
                -- Left shift the multiplicand register: A
                A <= A((2*dp_width)-2 downto 0) & '0';
					 -- Right shift the multiplier register: Q
                Q <= '0' & Q(dp_width-1 downto 1);
                count <= count + 1;
					 
					 -- if 32nd repetition
                if count = dp_width then
                    done <= '1';
                end if;
            end if;
        end if;
    end process;
	 product <= P;
end Behavioral;
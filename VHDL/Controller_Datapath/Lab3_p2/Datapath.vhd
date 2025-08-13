library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Datapath is
    generic (dp_width : integer := 32);
    Port ( clock, reset, load, sub, shiftQ, shiftR : in STD_LOGIC;
           quotient : out STD_LOGIC_VECTOR (dp_width-1 downto 0);
			  divisor : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
           remainder_in : in STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
			  remainder_out : out STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
           start, done : out STD_LOGIC);
end Datapath;

architecture Behavioral of Datapath is
    signal A : STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0); -- Multiplicand Register
    signal Q : STD_LOGIC_VECTOR (dp_width-1 downto 0);  -- Multiplier Register
    signal R, temp : STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0); -- Product Register
    signal Z : STD_LOGIC_VECTOR (dp_width-1 downto 0);
	 signal count : integer := 0;
begin
    process (clock, reset)
    begin
        Z <= (others => '0');
		  if reset = '1' then
            A <= (others => '0');
            Q <= (others => '0');
            R <= (others => '0');
            count <= 0;
            start <= '0';
            done <= '0';
        elsif rising_edge(clock) then
            if load = '1' then
                -- Initialize all registers
					 A <= divisor & Z;
                Q <= Z;
                R <= remainder_in;
                count <= 0; 
                start <= '1';
                done <= '0';
            elsif sub = '1' then
                count <= count + 1;
					 -- Subtract the remainder by the divisor and set the quotient bit accordingly; 
					 temp <= R - A; 	 
				elsif shiftQ = '1' then
					-- restore remainder register if remainder is negative.
					if temp((2*dp_width)-1) = '0' then
                    Q <= Q((dp_width)-2 downto 0) & '1';
						  R <= temp;
					 else
					     R <= temp + A;
						  Q <= Q((dp_width)-2 downto 0) & '0';
                end if;
					 -- if 33rd repetition, finalize outputs,
                if count = (dp_width + 1) then
						  done <= '1';
                end if; 
            elsif shiftR = '1' then
					 -- Right shift the divisor register: A
                A <= '0' & A((2*dp_width)-1 downto 1);
            end if;
        end if;
    end process;
	 quotient <= Q;
	 remainder_out <= R;
end Behavioral;
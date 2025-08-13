LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY testbench IS
END testbench;
ARCHITECTURE multiplier_arch OF testbench IS
                                         
COMPONENT Lab3_p2
    generic (dp_width : integer := 32); -- Width of the multiplier
    Port ( Clock, Reset : in STD_LOGIC;
           divisor : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
			  remainder_in : in STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
			  quotient : out STD_LOGIC_VECTOR (dp_width-1 downto 0);
           remainder_out : out STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
           start : in STD_LOGIC;
           ready : out STD_LOGIC);
end component;

SIGNAL quotient_sig : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL clock_sig : STD_LOGIC := '0';
SIGNAL r_in : STD_LOGIC_VECTOR(63 DOWNTO 0);
SIGNAL r_out : STD_LOGIC_VECTOR(63 DOWNTO 0);
SIGNAL divisor_in : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL reset_sig : STD_LOGIC;
SIGNAL start_div : STD_LOGIC;
SIGNAL ready_for_div : STD_LOGIC;

BEGIN
	DUT: Lab3_p2 port map (clock_sig, reset_sig, divisor_in, r_in, quotient_sig, r_out, start_div, ready_for_div);                                           
                                                                                
	clock_sig <= not clock_sig after 50 ns;

   divisor_in <= "00000000000000000000000000000000",
						"00000000000000000000000000000100" after 175ns;
	
   r_in <= "0000000000000000000000000000000000000000000000000000000000000000",
							"0000000000000000000000000000000000000000000000000000000000010101" after 175ns;
							
	start_div <= '0', '1' after 225 ns, '0' after 275 ns;

   reset_sig <= '0', '1' after 75 ns, '0' after 125 ns;
                                                                                                          
END multiplier_arch;

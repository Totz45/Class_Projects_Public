LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY testbench IS
END testbench;
ARCHITECTURE multiplier_arch OF testbench IS
                                         
COMPONENT Lab3_p1
    generic (dp_width : integer := 32);
    Port ( Clock, Reset : in STD_LOGIC;
           multiplicand, multiplier : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
           product : out STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
           start : in STD_LOGIC;
           ready : out STD_LOGIC);
end component;

SIGNAL product_sig : STD_LOGIC_VECTOR(63 DOWNTO 0);
SIGNAL clock_sig : STD_LOGIC := '0';
SIGNAL multiplicand_in : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL multiplier_in : STD_LOGIC_VECTOR(31 DOWNTO 0);
SIGNAL reset_sig : STD_LOGIC;
SIGNAL start_mul : STD_LOGIC;
SIGNAL ready_for_mul : STD_LOGIC;

BEGIN
	DUT: Lab3_p1 port map (clock_sig, reset_sig, multiplicand_in, multiplier_in, product_sig, start_mul, ready_for_mul);                                           
                                                                                
	clock_sig <= not clock_sig after 50 ns;

   multiplier_in <= "00000000000000000000000000000000",
						"00000000000000000000000000000100" after 175ns;
	
   multiplicand_in <= "00000000000000000000000000000000",
							"00000000000000000000000000010101" after 175ns;
							
	start_mul <= '0', '1' after 225 ns, '0' after 275 ns;

   reset_sig <= '0', '1' after 75 ns, '0' after 125 ns;
                                                                                                          
END multiplier_arch;

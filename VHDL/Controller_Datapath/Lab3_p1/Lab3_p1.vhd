library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Lab3_p1 is
    generic (dp_width : integer := 32); -- Width of the multiplier
    Port ( Clock, Reset : in STD_LOGIC;
           multiplicand, multiplier : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
           product : out STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
           start : in STD_LOGIC;
           ready : out STD_LOGIC);
end Lab3_p1;

architecture Structural of Lab3_p1 is
    signal load_sig, add_sig, shift_sig : STD_LOGIC;
    signal internal_start, internal_done : STD_LOGIC;
	 
	 component Controller
        Port ( clk, rst, start, multi_done : in STD_LOGIC;
               load_reg, add_reg, shift_reg : out STD_LOGIC);
    end component;
    
	 component Datapath
        generic (dp_width : integer := 32);
        Port ( clock, reset, load, add, shift : in STD_LOGIC;
               multiplicand, multiplier : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
               product : out STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
               start, done : out STD_LOGIC);
    end component;

begin
    DUT1 : Controller Port map (Clock, Reset, start, internal_done, load_sig, add_sig, shift_sig);

    DUT2 : Datapath Generic map (dp_width => 32) 
							Port map (Clock, Reset, load_sig, add_sig, shift_sig, multiplicand, multiplier, product, internal_start, internal_done);

    -- Connect internal signals
    internal_start <= start;

    -- Output done signal
    ready <= internal_done;

end Structural;
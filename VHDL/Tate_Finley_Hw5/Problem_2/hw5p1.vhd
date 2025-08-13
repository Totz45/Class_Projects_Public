library IEEE;
use IEEE.STD_LOGIC_1164.all;

library work;
use work.TTU.all;

entity hw5p1 is port(
  x: in STD_LOGIC;
  CLK: in STD_LOGIC;
  Reset: in STD_LOGIC;
  sevSeg: out STD_LOGIC_VECTOR(7 downto 0);
  z: out STD_LOGIC);  
end entity hw5p1;

-- ---------------------------------------
--   THE CRUX OF YOUR DESIGN GOES IN THIS
--    SECTION.  SPECIFICALLY, 
-- ---------------------------------------
architecture behavior of hw5p1 is

  type State_Type is (a, b, c, d);
		signal Current_State : State_Type;
		signal Next_State : State_Type;
  
  begin
	 STATE_MEMORY : process(CLK)
	 begin
		if (CLK'event and CLK = '1') then
		   if (Reset = '1') then
				Current_State <= a;
			else
				Current_State <= Next_State;
			end if;
		end if;
	 end process;
	 
	 NXT_STATE: process (x, Current_State)
	 begin
		case Current_State is
			when a => if x = '0' then Next_State <= b;
						 else Next_State <= c;
						 end if;
			when b => if x = '0' then Next_State <= c;
						 else Next_State <= d;
						 end if;
			when c => if x = '0' then Next_State <= b;
						 else Next_State <= d;
						 end if;
			when d => if x = '0' then Next_State <= c;
						 else Next_State <= a;
						 end if;
			when others => Next_State <= a;
		end case;
	 end process;
	 
	 Out_Z: process (x, Current_State)
	 begin
	   case Current_State is
			when a => if x = '0' then Z <= '1';
						 else Z <= '0';
						 end if;
			when b => if x = '0' then Z <= '0';
						 else Z <= '1';
						 end if;
			when c => if x = '0' then Z <= '0';
						 else Z <= '1';
						 end if;
			when d => if x = '0' then Z <= '1';
						 else Z <= '0';
						 end if;			 
			when others => Z <= '0';
		end case;
	 end process;
	 
	 Out_State: process (Current_State)
	 begin
			case Current_State is
				when a => sevSeg <= "10001000";
				when b => sevSeg <= "10000011";
				when c => sevSeg <= "11000110";
				when d => sevSeg <= "10100001";
				when others => sevSeg <= "10101010";
			end case;
	 end process;
	
	
    --U0: entity work.my_INV(RTL) port map (in0, in0bar);

    
end architecture behavior;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Controller is
    Port ( clk, rst, start, multi_done : in STD_LOGIC;
           load_reg, sub_reg, shiftQ_reg, shiftR_reg : out STD_LOGIC);
end Controller;

architecture Behavioral of Controller is
    type state_type is (IDLE, LOAD, SUB, SHIFTQ, SHIFTR, DONE);
    signal state_reg, next_state : state_type;
begin
    process (clk, rst)
    begin
        if rst = '1' then
            state_reg <= IDLE;
        elsif rising_edge(clk) then
            state_reg <= next_state;
        end if;
    end process;

    process (state_reg, start, multi_done)
    begin
        case state_reg is
            when IDLE =>
                if start = '1' then
                    next_state <= LOAD;
                else
                    next_state <= IDLE;
                end if;
            when LOAD =>
                next_state <= SUB;
            when SUB =>
                next_state <= SHIFTQ;
				when SHIFTQ =>
                next_state <= SHIFTR;
            when SHIFTR =>
                if multi_done = '1' then
                    next_state <= DONE;
                else
                    next_state <= SUB;
                end if;
            when DONE =>
                next_state <= IDLE;
            when others =>
                next_state <= IDLE;
        end case;
    end process;

    load_reg <= '1' when state_reg = LOAD else '0';
    sub_reg <= '1' when state_reg = SUB else '0';
    shiftQ_reg <= '1' when state_reg = SHIFTQ else '0';
	 shiftR_reg <= '1' when state_reg = SHIFTR else '0';
end Behavioral;
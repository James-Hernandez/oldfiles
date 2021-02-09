library ieee;
use ieee.std_logic_1164.all;

entity NOT_gate is
port( x: in std_logic;
      --y: in std_logic;
      y: out std_logic
     );
end NOT_gate;

architecture behav of NOT_gate is
begin

   process(x)
   begin
      if (x='1') then
         y <= '0';
      else
         y <= '1';
      end if;
   end process;
end behav;

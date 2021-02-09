library ieee;
use ieee.std_logic_1164.all;

entity Mux_4x1TB is
end Mux_4x1TB;

architecture TB of Mux_4x1TB is

   --the component we are testing is AND_OR
   component Mux_4x1 is
   port( op: in std_logic_vector (1 downto 0);
       x1: in std_logic;
      x2: in std_logic;
      x3: in std_logic;
	  x4: in std_logic;
	  
      y:  out std_logic
        );
   end component;
   
   signal ops: std_logic_vector (1 downto 0);
   signal a1, a2, a3, a4, b: std_logic;
   
   begin
      test_Mux_4x1: Mux_4x1 port map (ops, a1, a2, a3, a4, b);

   process 
      begin
         --case1
		 ops <= "00";
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		 a4 <= '0';
		 
		 
         wait for 10 ns;
         
         --case2
         ops <= "00";
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 a4 <= '1';
		 
		
         wait for 10 ns;

         --case3
         ops <= "01";
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 a4 <= '0';
		 
         wait for 10 ns;
         
         --case4
         ops <= "01";
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 a4 <= '1';
		
         wait for 10 ns;

         --case5
         ops <= "10";
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 a4 <= '0';
         wait for 10 ns;

         --case6
         ops <= "10";
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 a4 <= '1';
		 
         wait for 10 ns;


         wait;
   end process;
end TB;

configuration CFG_TB of Mux_4x1TB is 
   for TB
   end for;
end CFG_TB; --or, lower case is OK (end cfg_TB)

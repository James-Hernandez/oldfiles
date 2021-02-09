library ieee;
use ieee.std_logic_1164.all;

entity XOR_gate is
port( x: in std_logic;
      y: in std_logic;
      z: out std_logic
     );
end XOR_gate;

architecture struct of XOR_gate is

component NOT_gate is
	port( x: in std_logic;
	      y: out std_logic
	    );
	end component;
	
  component AND_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
   end component;
   
 

   component OR_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
	
   end component;
    

   signal temp1: std_logic; --to store the output of the not gate
   signal temp2: std_logic; --to store the output of the other not gate
   signal temp3: std_logic;--to store the output of and1 gate
   signal temp4: std_logic;--to store the output of and2 gate
begin

   map_NOT_gate1: NOT_gate port map (y,temp1);
   map_AND_gate1: AND_gate port map (x, temp1, temp4);
   map_NOT_gate2: NOT_gate port map (x,temp2);
   map_AND_gate2: AND_gate port map (y, temp2, temp3); --now, temp1 holds the output of the AND
   map_OR_gate:  OR_gate port map (temp4,temp3, z); 
end struct;

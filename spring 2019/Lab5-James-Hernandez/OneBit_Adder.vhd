library ieee;
use ieee.std_logic_1164.all;

entity OneBit_Adder is
port( x1: in std_logic;
      x2: in std_logic;
      x3: in std_logic;
      y1: out std_logic;
	  y2: out std_logic
      );
end OneBit_Adder;

architecture struct of OneBit_Adder is

   --use previously designed subcomponents
   
  component OR_gate is
	port( x: in std_logic;
		  y: in std_logic;
	      z: out std_logic
	    );
	end component;
	
  component AND_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
   end component;
   
 
   component XOR_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
	
   end component;
    

   signal temp1: std_logic; --to store the output of the not gate
   signal temp2: std_logic;--to store the output of and1 gate
   signal temp3: std_logic;--to store the output of and2 gate
begin
   
   --map signals of the outer component to subcomponents - idea of parameter passing
   map_XOR_gate1: XOR_gate port map (x1,x2,temp1);
   map_AND_gate1: AND_gate port map (x1, x2, temp2);
   map_AND_gate2: AND_gate port map (temp1, x3, temp3); --now, temp1 holds the output of the AND
   map_OR_gate:  OR_gate port map (temp2,temp3, y2); --then, temp1 is passed to the OR as an input
   map_XOR_gate2: XOR_gate port map (x3,temp1, y1);
                                             --output of the OR becomes the output(y) of AND_OR

end struct;

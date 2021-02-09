library ieee;
use ieee.std_logic_1164.all;

entity Decoder_4 is
port( x1: in std_logic;
      x2: in std_logic;
      y1: out std_logic;
	  y2: out std_logic;
	  y3: out std_logic;
	  y4: out std_logic
      );
end Decoder_4;

architecture struct of Decoder_4 is

   --use previously designed subcomponents
   
  
	
  component AND_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
   end component;
   
 
   component NOT_gate is
   port( x: in std_logic;
         y: out std_logic
        );
	
   end component;
    

   signal temp1: std_logic; --to store the output of the not gate
   signal temp2: std_logic;--to store the output of and1 gate
   signal temp3: std_logic;--to store the output of and2 gate
   signal temp4: std_logic;
begin
   
   --map signals of the outer component to subcomponents - idea of parameter passing
   map_NOT_gate1: NOT_gate port map (x1, temp1);
   map_NOT_gate2: NOT_gate port map (x2, temp2);
   map_AND_gate1: AND_gate port map (temp1, temp2, y1);
   
   map_NOT_gate3: NOT_gate port map (x1, temp3);
   map_AND_gate2: AND_gate port map (x2, temp3, y2);
   
   map_NOT_gate4: NOT_gate port map (x2, temp4);
   map_AND_gate3: AND_gate port map (x1, temp4, y3); --now, temp1 holds the output of the AND
   
   map_AND_gate4: AND_gate port map (x1,x2, y4);
                                             --output of the OR becomes the output(y) of AND_OR

end struct;

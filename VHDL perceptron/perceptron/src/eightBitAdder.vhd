library IEEE;
use IEEE.std_logic_1164.all;

entity eightBitAdder is
    port(inA : in std_logic_vector(7 downto 0);
         inB : in std_logic_vector(7 downto 0);
         SUM : out std_logic_vector(7 downto 0));
end eightBitAdder;

architecture eightBitAdderLogic of eightBitAdder is

    component halfAdder
    port(A : in std_logic; 
         B : in std_logic;
         SUM : out std_logic;
         CARRY : out std_logic);
    end component;

    component fullAdder
    port(A : in std_logic; 
         B : in std_logic;
         C : in std_logic;
         SUM : out std_logic;
         CARRY : out std_logic);
    end component;

    signal carry0 : std_logic;
    signal carry1 : std_logic;
    signal carry2 : std_logic;
    signal carry3 : std_logic;
    signal carry4 : std_logic;
    signal carry5 : std_logic;
    signal carry6 : std_logic;
    signal carry7 : std_logic;

    begin
        start: halfAdder
        port map (A => inA(0), 
                  B => inB(0),
                  SUM => SUM(0),
                  CARRY => carry0);
        

        full1: fullAdder
        port map (A => inA(1), 
                  B => inB(1),
                  C => carry0,
                  SUM => SUM(1),
                  CARRY => carry1);

        full2: fullAdder
        port map (A => inA(2), 
                  B => inB(2),
                  C => carry1,
                  SUM => SUM(2),
                  CARRY => carry2);

        full3: fullAdder
        port map (A => inA(3), 
                  B => inB(3),
                  C => carry2,
                  SUM => SUM(3),
                  CARRY => carry3);

        full4: fullAdder
        port map (A => inA(4), 
                  B => inB(4),
                  C => carry3,
                  SUM => SUM(4),
                  CARRY => carry4);

        full5: fullAdder
        port map (A => inA(5), 
                  B => inB(5),
                  C => carry4,
                  SUM => SUM(5),
                  CARRY => carry5);
        
        full6: fullAdder
        port map (A => inA(6), 
                  B => inB(6),
                  C => carry5,
                  SUM => SUM(6),
                  CARRY => carry6);

        full7: fullAdder
        port map (A => inA(7), 
                  B => inB(7),
                  C => carry6,
                  SUM => SUM(7),
                  CARRY => carry7);
        
end eightBitAdderLogic;
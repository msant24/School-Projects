import java.util.Scanner;

public class Nim {
    Pile pile;

    public Nim(){
        pile = new Pile();
    }

    public void Play(){
        Nim nim = new Nim();
        String winner = "";
        Player player1 = new Human("");
        Player player2 = new Human("");
        Scanner input = new Scanner(System.in);
        int pick = 0;
        System.out.println("Who will be the first player? (Type \"1\": Human, Type \"2\": SmartComputer, Type \"3\": BelowAverageComputer)");
        pick = input.nextInt();
        if(pick == 1) {
            String humName;
            System.out.println("Type the name for this player");
            humName = input.next();
            player1 = new Human(humName);
        }
        if(pick == 2) {
            String smartName;
            System.out.println("Type the name for this player");
            smartName = input.next();
            player1 = new SmartComputer(smartName);
        }
        if(pick == 3) {
            String averageName;
            System.out.println("Type the name for this player");
            averageName = input.next();
            player1 = new BelowAverageComputer(averageName);
        }

        System.out.println("Who will be the Second player? (Type \"1\": Human, Type \"2\": SmartComputer, Type \"3\": BelowAverageComputer)");
        pick = input.nextInt();
        if(pick == 1) {
            
            String humName;
            System.out.println("Type the name for this player");
            humName = input.next();
            player2 = new Human(humName);
        }
        if(pick == 2) {
            String smartName;
            System.out.println("Type the name for this player");
            smartName = input.next();
            player2 = new SmartComputer(smartName);
        }
        if(pick == 3) {
            String averageName;
            System.out.println("Type the name for this player");
            averageName = input.next();
            player2 = new BelowAverageComputer(averageName);
        }

        System.out.println("GAME START!!!");
        
        while(nim.pile.pile > 0){
            System.out.println("There is/are " + nim.pile.getPile() + " marble(s) left");
            System.out.println("it's " + player1.playerName() + "'s turn");
            player1.Move(nim.pile.pile);
            System.out.println(player1.playerName() + " takes out " + player1.marblesTaken() + " marble(s)");
            nim.pile.TakeMarbles(player1.marblesTaken());
            if(nim.pile.pile == 0){
                winner = player2.playerName();
            }else{
            System.out.println("There is/are " + nim.pile.getPile() + " marble(s) left");
            System.out.println("it's " + player2.playerName() + "'s turn");
            player2.Move(nim.pile.pile);
            System.out.println(player2.playerName() + " takes out " + player2.marblesTaken() + " marble(s)");
            nim.pile.TakeMarbles(player2.marblesTaken());
            if(nim.pile.pile == 0){
                winner = player1.playerName();
            }
        }
        }
        
        System.out.println("The winner is: " + winner);
    }
}
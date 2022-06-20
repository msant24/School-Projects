import java.util.Random;
import java.util.Scanner;
public interface Player {

    int marblesTaken();

    String playerName();

	void Move(int pile);

}

class Human implements Player {
    int marbles;
    String name;
    
    public Human(String name) {
        this.name = name;
    }

    public void Move(int pilesize){
        int num;
        Scanner input = new Scanner(System.in);
        marbles = 0;
        while(marbles == 0){
        System.out.println("Select the amount of marbles that you would like to take out ");
        num = input.nextInt();
        if(pilesize == 1 && num == 1){
            marbles = 1;
        }else{
        if(num > pilesize/2){
            marbles = 0;
        }else{
            marbles = num;
        }
    }
    }
}

    public int marblesTaken() {
        return marbles;
    }

    public String playerName() {
        return name;
    }

    
}

class BelowAverageComputer implements Player {
    int marbles;
    String name;

    public BelowAverageComputer(String name) {
        this.name = name;
    }
    public void Move(int pilesize){
        Random rand = new Random();
        if(pilesize <= 2){
            marbles = 1;
        }else{
        marbles = rand.nextInt((pilesize/2)) + 1;
        }
    }
    public int marblesTaken() {
        return marbles;
    }

    public String playerName() {
        return name;
    }

    
}

class SmartComputer implements Player {
    int marbles;
    String name;
    
    public SmartComputer(String name) {
        this.name = name;
    }
    public void Move(int pilesize){
        if(pilesize == 63 || pilesize == 31 || pilesize == 15 || pilesize == 7 || pilesize == 3 || pilesize == 1){ 
            marbles = 1;
        }
        if(pilesize > 63){
            marbles = pilesize - 63;
        }
        if(pilesize < 63 && pilesize > 31){
            marbles = pilesize - 31;
        }
        if(pilesize < 31 && pilesize > 15){
            marbles = pilesize - 15;
        }
        if(pilesize < 15 && pilesize > 7){
            marbles = pilesize - 7;
        }
        if(pilesize < 7 && pilesize > 3){
            marbles = pilesize - 3;
        }
        if(pilesize == 2){
            marbles = 1;
        }
        }
    public int marblesTaken() {
        return marbles;
    }

    public String playerName() {
        return name;
    }

    
}
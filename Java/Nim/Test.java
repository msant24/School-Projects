import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        String choice = "Y";
        Scanner input = new Scanner(System.in);
        while(choice.equals("Y")){
        Nim nim = new Nim();
        nim.Play(); 
        System.out.println("Type \"Y\" if you would like to play again");
        choice = input.next();
        }
    }
}
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Scanner;

public class Restaurant {

  public static void main(String[] args){
	  
    int diners = 0;  // number of diners
    int tables = 0;  // number of tables
    int cooks = 0;   // number of cooks
    int scale = 100; // scaling of time
    
    // read from a file, ignore spaces
    File file = new File(args[0]);
    List<Integer> list = new ArrayList<Integer>();
    Scanner scanner;
	try {
		scanner = new Scanner(file);
	    while (scanner.hasNextInt())
	        list.add(scanner.nextInt());
	} catch (FileNotFoundException e1) {
		e1.printStackTrace();
	}
        
    diners = list.get(0);
    tables = list.get(1);
    cooks = list.get(2);
   
    System.out.println("Welcome to restaurant 6431! $_$");
    System.out.println("*************************************************************");
    System.out.println("Diners: " + diners);
    System.out.println("Tables: " + tables);
    System.out.println("Cooks: " + cooks);
    System.out.println("*************************************************************");
    

    TableCoordinator tableCoordeinator = new TableCoordinator(tables);    
    MachineCoordinator machineCoordinator = new MachineCoordinator();

    // create threads for each cook
    Cook[] cookThread = new Cook[cooks];
    for(int i=0;i<cooks;i++){
      cookThread[i] = new Cook("Cook"+(i+1), i, scale, machineCoordinator);
      cookThread[i].start();
    }
    CookCoordinator cookCoordinator = new CookCoordinator(cookThread, cooks);

    // create threads for each diner
    Diner[] dinerThread = new Diner[diners];
    LinkedHashMap<Integer, ArrayList<Diner>> lhm  = new LinkedHashMap<Integer, ArrayList<Diner>>();
    for(int i=3,n=0;n<diners;i+=5,n++) {
      dinerThread[n] = new Diner("Diner"+(n+1), scale, list.get(i),list.get(i+1),list.get(i+2),list.get(i+3),list.get(i+4),tableCoordeinator, cookCoordinator);
      if(!lhm.containsKey(list.get(i)))
        lhm.put(list.get(i), new ArrayList<Diner>());
      lhm.get(list.get(i)).add(dinerThread[n]);
    }
    
    for(int i=0, n=0; i<=120; i++){
      if(lhm.containsKey(i)){
    	n++;
        for(Diner dt : lhm.get(i))
          dt.start();
      }
      if(n == diners) break;
      try{
        Thread.sleep(1*scale);
      }catch(InterruptedException e){
        e.printStackTrace();
      }
    }    
    
    // get the last diner timeStamp
    long LeftTime = 0;
    for(int i=0;i<diners;i++){
      if(dinerThread[i].getThread().isAlive()){
        try{
          dinerThread[i].getThread().join();
        }catch(InterruptedException e){
          e.printStackTrace();
        }
        if(LeftTime < dinerThread[i].getLeftTime()) 
           LeftTime = dinerThread[i].getLeftTime();
      }
    }
    
    for(int i=0; i < cooks; i++){
    	cookThread[i].end();
    }
    
    System.out.println("The last diner left at "+ LeftTime);
    System.out.println("*************************************************************");
    System.out.println("Thank you for your visit and have a nice day! $_$ \n"); 
  }
}

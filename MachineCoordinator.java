
class MachineCoordinator {

  private boolean burgerMachineFree;
  private boolean friesMachineFree;
  private boolean cokeMachineFree;
  private boolean sundaesMachineFree;
  public int bugerTimeStamp;
  public int friesTimeStamp;
  public int cokeTimeStamp;
  public int sundaesTimeStamp;
  
  public MachineCoordinator(){
	  burgerMachineFree = true;
	  friesMachineFree = true;
	  cokeMachineFree = true;
	  sundaesMachineFree = true;
	  bugerTimeStamp = 0;
	  friesTimeStamp = 0;
	  cokeTimeStamp = 0;
	  sundaesTimeStamp = 0;
  }
  
  // need has 4 bit, each bit stands for the need of a kind of food
  // e.g.  1010  means need of burger and coke
  synchronized String getMachine(int need){
	while(!(burgerMachineFree && ((need&8) == 8)) && !(friesMachineFree && ((need&4) == 4)) && !(cokeMachineFree && ((need&2) == 2))
			&& !(sundaesMachineFree && ((need&1) ==1))){
	  try{
	       wait();
	      }catch(InterruptedException e){
	          e.printStackTrace();
	    }
	}
    if(burgerMachineFree && ((need&8) == 8)){
    	burgerMachineFree = false;
      return "burger";
    }else if(friesMachineFree && ((need&4) == 4)){
    	friesMachineFree = false;
      return "fries";
    }else if(cokeMachineFree && ((need&2) == 2)){
    	cokeMachineFree = false;
      return "coke";
    }else if(sundaesMachineFree && ((need&1) ==1)){
    	sundaesMachineFree = false;	
      return "sundaes";
    }
    return "default";
  }

  synchronized void putMachine(String str) {
    if(str.equals("burger")){
    	burgerMachineFree = true;
    }else if(str.equals("fries")){
    	friesMachineFree = true;
    }else if(str.equals("coke")){
    	cokeMachineFree = true;
    }else if(str.equals("sundaes")){
    	sundaesMachineFree = true;
    }
    notifyAll();
  }

}

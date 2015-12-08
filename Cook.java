
class Cook extends Thread {
	
  private int timeStamp;
  private String threadName;
  private MachineCoordinator machineCoordinator;
  private int scale;
  private int[] order;
  private String dinerID;
  private int resource;
  private Thread t;
  private volatile boolean hasOrder;
  private volatile boolean run;
  
  public Cook(String threadName, int id, int scale, MachineCoordinator mc){
    this.threadName = threadName;
    this.machineCoordinator = mc;
    this.scale = scale;
    this.run = true;
    this.hasOrder = false;
    this.order = new int[]{0,0,0,0};
  }

  public void start(){
	if(t==null){
	t = new Thread(this, threadName);
	t.start();
	}
  }

  public void end(){
	resource = 0;
    hasOrder = true;
	run = false;
  }
  
  public void run() {
    while(run){
      while(!hasOrder);
      while(resource>0){
    	int need = getNeed();
        String machine = machineCoordinator.getMachine(need);
        if(machine.equals("burger")){
          timeStamp = Math.max(timeStamp, machineCoordinator.bugerTimeStamp);
          machineCoordinator.bugerTimeStamp = timeStamp;
          System.out.println(dinerID+"'s order was using burger machine at " + timeStamp);
          timeStamp += 5*order[0];
          machineCoordinator.bugerTimeStamp += 5*order[0];
          try {
			Thread.sleep(5*order[0]*scale);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
          order[0] = 0;
        }else if (machine.equals("fries")) {
          timeStamp = Math.max(timeStamp, machineCoordinator.friesTimeStamp);
          machineCoordinator.friesTimeStamp = timeStamp;
          System.out.println(dinerID+"'s order was using fries machine at " + timeStamp);
          timeStamp += 3*order[1];
          machineCoordinator.friesTimeStamp += 3*order[1];
          try{
            Thread.sleep(3*order[1]*scale);
          }catch(InterruptedException e){
            e.printStackTrace();
          }
          order[1] = 0;
        }else if (machine.equals("coke")){
          timeStamp = Math.max(timeStamp, machineCoordinator.cokeTimeStamp);
          machineCoordinator.cokeTimeStamp = timeStamp;
          System.out.println(dinerID+"'s order was using cokes machine at " + timeStamp);
          timeStamp += 2;
          machineCoordinator.cokeTimeStamp += 2;
          try{
            Thread.sleep(2*scale);
          }catch(InterruptedException e){
            e.printStackTrace();
          }
          order[2] = 0;
        }else if (machine.equals("sundaes")){
          timeStamp = Math.max(timeStamp, machineCoordinator.sundaesTimeStamp);
          machineCoordinator.sundaesTimeStamp = timeStamp;
          System.out.println(dinerID+"'s order was using sundaes machine at " + timeStamp);
          timeStamp += 1;
          machineCoordinator.sundaesTimeStamp += 1;
          try{
            Thread.sleep(1*scale);
          }catch(InterruptedException e){
            e.printStackTrace();
          }
          order[3] = 0;
        }
        machineCoordinator.putMachine(machine);
        resource = order[0]+order[1]+order[2]+order[3];
        need = getNeed();
      }
      if(dinerID!=null)
    	  hasOrder = false;
    }
    return;
  }
  
  int getNeed(){
	int need = 0;
	for(int i = 0; i < 4; i++){
		need <<= 1;
		if(order[i] > 0) need |= 1;
	}
    return need;
  }
     
  void processOrder(int burgers, int fries, int coke, int sundaes, String dinerName, int timeArrived){
    order[0] = burgers;
    order[1] = fries;
    order[2] = coke;
    order[3] = sundaes;
    dinerID = dinerName;
    resource = order[0]+order[1]+order[2]+order[3];
    timeStamp = Math.max(timeStamp, timeArrived);
    hasOrder = true;
    while(hasOrder);
    return;
  }
  
  public String getThreadName(){
    return threadName;
  }
  
  public int getTimeStamp(){
	  return timeStamp;
  }

}

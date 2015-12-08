
class Diner extends Thread {

  private Thread t;
  private String threadName;
  private int timeStamp;
  private int scale;
  private int burgers;
  private int fries;
  private int coke;
  private int sundaes;
  private TableCoordinator tableCoordinator;
  private CookCoordinator cookCoordinator;

  Diner(String threadName, int scale, int timeStamp, int burgers, int fries, int cook ,int sundaes, TableCoordinator tc, CookCoordinator cc) {
    this.threadName = threadName;
    this.scale = scale;
    this.timeStamp = timeStamp;
    this.burgers = burgers;
    this.fries = fries;
    this.coke = cook;
    this.sundaes = sundaes;
    this.tableCoordinator = tc;
    this.cookCoordinator = cc;
  }

  public void start(){
	    if(t==null){
	      t = new Thread(this, threadName);
	      t.start();
	    }
  }
  
  public void run(){
    int table = tableCoordinator.getTable();
    timeStamp = Math.max(timeStamp, tableCoordinator.timeStamp[table-1]);   
    System.out.println(threadName+" was seated at table"+table+" at "+ timeStamp);
    Cook cook = cookCoordinator.getCook();
    System.out.println(threadName+"'s order was processed by "+ cook.getThreadName());
    cook.processOrder(burgers, fries, coke, sundaes, threadName, timeStamp);
    timeStamp = cook.getTimeStamp();
    System.out.println(threadName+"'s food was brought to table at " + timeStamp);
    cookCoordinator.putCook(cook);
    try {
		Thread.sleep(30*this.scale);
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
    timeStamp += 30;
    tableCoordinator.timeStamp[table-1] = timeStamp;
    tableCoordinator.putTable(table);
  }

  public Thread getThread(){
    return t;
  }

  public long getLeftTime(){
	return timeStamp;
  }
  
}

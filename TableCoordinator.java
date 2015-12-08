
class TableCoordinator {

  private int tablesAvailable;
  private int tables;
  private int[] table;
  public int[] timeStamp;

  public TableCoordinator(int tables){
    this.tablesAvailable = tables;
    this.tables = tables;
    this.table = new int[tables];
    this.timeStamp = new int[tables];
    for(int i=0;i<tables;i++){
      table[i] = 0;
      timeStamp[i] = 0;
    }
  }
  
  synchronized int getTable(){
	    while(tablesAvailable==0){
	      try{
	        wait();
	      }catch(InterruptedException e){
	        e.printStackTrace();
	      }
	    }
	    int index = -1;
	    for(int i=0; i<tables; i++){
	      if(table[i]==0){
	        index = i;
	        break;
	      }
	    }
	    table[index] = 1;
	    tablesAvailable--;
	    return (index+1);
  }
  
  synchronized void putTable(int t){
	    table[t-1] = 0;
	    tablesAvailable++;
	    notifyAll();
  }
  
}

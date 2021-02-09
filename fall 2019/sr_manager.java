//frame code for programming assignment 5;
//file name must be same as the main class name, i.e., sr_manager.java
public class sr_manager //main class 
{ static sr1 r1 = new sr1(); // here we have our first source one 
  static sr2 r2 = new sr2();//here we have our second source two

  public static void main(String args[]) 
  {  
   //create and start 6 threads for 6 concurrent processes
   process flow[] = new process[6];// we make a process class array named
                                    //flow and we make 6 
   
   for(int i = 0; i < 6; i++){//here we have a for loop that will create
								//a thread for each index of the array and 
								//will output to the screen tht the thread has
								//began
   flow[i] = new process(i,r1,r2);
   flow[i].start();//begin thread process
   System.out.println("the thread process " +i+ " created!");//print
   }
  }
} 
 
class sr1 //class for shared resource r1
{ private static int avail1 = 3; //here we have our available slots for use

  //synchronized method cannot be interrupted; 
  //only one thread can access at a time; 
  public synchronized void acquire(int id) throws InterruptedException
											/* we have throws exception because we are
											making a blocking function that will will
											essentially block and continue others when finished
											*/
  { 
       while(avail1 == 0){/*if there are 0 available slots open then we will print out to 
							the screen that stream/flow with the current id the flow is
							waiting for will be presented to the screen*/
		   System.out.println("Stream" +id+ " is waiting for SR1.");//print
		   wait();//we have a wait function that slows down the function
	   }
  System.out.println("stream process " +id+ " acquries SR1.");
  /*Since there are 3 open at the start of the runtime we will print out that
the steam process with the current id has acquired the resource 1.  */
  avail1--;//and since they have acquired the sr1 we have to decrement the availability
  } 
         
  //synchronized method cannot be interrupted; 
  //only one thread can access at a time; 
  public synchronized void release(int id) 
  { 
    System.out.println("Stream "+id+ " releases sr1");
	/*just a simple output to the screen that the stream has released sr1*/
	notify();// now we use the notify() function to let other threads know ther is now
	         //one available
	avail1++;// we increment avail1 to show there is more available
  } 
}//class sr1 
 
class sr2 //class for shared resource r2
{ private static int avail2 = 2; //we make 2 avaliable resources to be shared

  //synchronized method cannot be interrupted; 
  //only one thread can access at a time; 
  public synchronized void acquire(int id) throws InterruptedException
  { 
											/* we have throws exception because we are
											making a blocking function that will will
											essentially block and continue others when finished
											*/
    while (avail2 == 0) {/*if there are 0 available slots open then we will print out to 
							the screen that stream/flow with the current id the flow is
							waiting for will be presented to the screen*/
			System.out.println("Stream " + id + " is waiting for SR2.");// simple print
			wait();//we have a wait function that slows down the function
		}
		System.out.println("Stream " + id + " acquires SR2.");
		/*Since there are 2 open at the start of the runtime we will print out that
the steam process with the current id has acquired the resource 2.  */
		avail2--;//and since they have acquired the sr1 we have to decrement the availability
  } 
         
  //synchronized method cannot be interrupted; 
  //only one thread can access at a time; 
  public synchronized void release(int id) 
  { 
   System.out.println("Stream " + id + " releases SR2.");
   /*just a simple output to the screen that the stream has released sr2*/
		// now we use the notify() function to let other threads know ther is now
		notify();
		avail2++;// we increment avail1 to show there is more available
  } 
}//class sr2 
 
class process extends Thread //thread class name is "process"
{ static sr1 r1; 
  static sr2 r2;
  private int id; 

  public process(int k, sr1 r1, sr2 r2) //constructor 
  { this.r1 = r1;
    this.r2 = r2;
    id = k;//we pass k in the constructor but it will be set to the id of the sr's
  } 
 
  public void run() 
  { 
    //acquire r1 and r2; 
    //display "process_i is working";
    //release r1 and r2;
		try {
			process.r1.acquire(id);//if the process has an error in checking for the aquire for r1 it will go into the catch block of code.
		} catch (InterruptedException e) {
			
			System.out.println("Exception: " + e.getMessage());//print out to the screen the exception and giving the message
		}
		
		try {
			process.r2.acquire(id);//if the process has an error in checking for the aquire for r2 it will go into the catch block of code.
		} catch (InterruptedException e) {
			
			System.out.println("Exception: " + e.getMessage());//print out to the screen the exception and giving the message
		}
		
		try {
			Thread.sleep(300);//asking the thread to sleep for 300 miliseconds 
		}
		catch (InterruptedException ex) {
			System.out.println("InterruptedException: " + ex.getMessage());
		}
		
		System.out.println(" --Flow process " + id + " is in process....");//will output the screen that the flow process for the specific id is working
		
		process.r1.release(id);//when the process is done it will relesase the resource r1 and go into the release function with the id
		process.r2.release(id);//when the process is done it will relesase the resource r2 and go into the release function with the id
		
  } 
  
}//class process 

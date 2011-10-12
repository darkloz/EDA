import CalculadoraApp.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;

import java.util.Properties;

class CalculadoraImpl extends CalculadoraPOA {
    private ORB orb;

    public void setORB(ORB orb_val) {
    orb = orb_val; 
    }

    // implementacion de suma
    public double suma( double a, double b){
        return a+b;
    }
    // implementacion de resta
    public double resta( double a, double b){
        return a-b;
    }
    // implementacion de multiplicacion
    public double multiplicacion( double a, double b){
        return a*b;
    }
    // implementacion de division   
    public double division( double a, double b){
        return a/b;
    }


}


public class ServidorCalculadora {

  public static void main(String args[]) {
    try{

      ORB orb = ORB.init(args, null); // crea e inicializa el ORB

      //obtiene referencia a rootpoa & activa el POAManager
      POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
      rootpoa.the_POAManager().activate();

      // crea el servicio y lo registra con el ORB
      CalculadoraImpl calculadoraImpl = new CalculadoraImpl();
      calculadoraImpl.setORB(orb); 

      // obtiene la referencia del servicio
      org.omg.CORBA.Object ref = rootpoa.servant_to_reference(calculadoraImpl);
      Calculadora href = CalculadoraHelper.narrow(ref);
	  
      // obtiene el nombre raiz del contexto
      org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
      NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

      // bind the Object Reference in Naming
      String name = "Calculadora";
      NameComponent path[] = ncRef.to_name( name );
      ncRef.rebind(path, href);

      System.out.println(" Inicio el servidor :) ");

      // wait for invocations from clients
      orb.run();
    } 
	
      catch (Exception e) {
        System.err.println("ERROR: " + e);
        e.printStackTrace(System.out);
      }
	  
      System.out.println(" Termino el servidor ");
	
  }
}

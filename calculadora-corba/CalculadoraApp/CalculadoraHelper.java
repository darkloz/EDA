package CalculadoraApp;

abstract public class CalculadoraHelper
{
  private static String  _id = "IDL:CalculadoraApp/Calculadora:1.0";

  public static void insert (org.omg.CORBA.Any a, CalculadoraApp.Calculadora that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static CalculadoraApp.Calculadora extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (CalculadoraApp.CalculadoraHelper.id (), "Calculadora");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static CalculadoraApp.Calculadora read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_CalculadoraStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, CalculadoraApp.Calculadora value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static CalculadoraApp.Calculadora narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof CalculadoraApp.Calculadora)
      return (CalculadoraApp.Calculadora)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      CalculadoraApp._CalculadoraStub stub = new CalculadoraApp._CalculadoraStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

  public static CalculadoraApp.Calculadora unchecked_narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof CalculadoraApp.Calculadora)
      return (CalculadoraApp.Calculadora)obj;
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      CalculadoraApp._CalculadoraStub stub = new CalculadoraApp._CalculadoraStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}

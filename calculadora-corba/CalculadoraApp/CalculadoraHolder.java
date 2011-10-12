package CalculadoraApp;

public final class CalculadoraHolder implements org.omg.CORBA.portable.Streamable
{
  public CalculadoraApp.Calculadora value = null;

  public CalculadoraHolder ()
  {
  }

  public CalculadoraHolder (CalculadoraApp.Calculadora initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = CalculadoraApp.CalculadoraHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    CalculadoraApp.CalculadoraHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return CalculadoraApp.CalculadoraHelper.type ();
  }

}

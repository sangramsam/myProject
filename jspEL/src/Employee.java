
public class Employee implements person
{
	private String name;
	private int id;
	private Address address;
public Employee()
{
	
}
@Override
public String getName() {
	return this.name;
	
}
@Override
public void setName(String nm) {
	this.name=nm;
	
}
public int getId()
{
	return id;
}
public void setId(int id)
{
	this.id=id;
}
public Address getAddress()
{
	return address;
}
public void setAddress(Address address)
{
	this.address=address;
}
public String toString()
{
	return "id="+id+",name="+name+",Address="+address;
}
}
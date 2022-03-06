package homero;

public class Homerseklet {
	private double temperature;
	private units unit;
	
	public enum units {
		CELSIUS, KELVIN
	}
	
	public Homerseklet(double temperature, units unit) {
		this.temperature = temperature;
		this.unit = unit;
	}

	public Homerseklet(double temperature) {
		this.temperature = temperature;
		this.unit = units.CELSIUS;
	}

	@Override
	public String toString() {
		return "Homerseklet [temperature=" + temperature + ", unit=" + unit + "]";
	}

	public double getTemperature() {
		return temperature;
	}

	public void setTemperature(double temperature) {
		this.temperature = temperature;
	}

	public units getUnit() {
		return unit;
	}

	public void setUnit(units unit) {
		this.unit = unit;
	}
	
	public double konvHomerseklet(double temperature, units unit) {
		if(unit == units.CELSIUS) {
			return temperature + 273.15;
		}else if(unit == units.KELVIN) {
			return temperature - 273.15;
		}else {
			return 0;
		}
	}
	
	
}

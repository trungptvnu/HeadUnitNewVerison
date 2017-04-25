
var city;

function setCityName(name) { city = name; }

function addZero(i) {
    if (i < 10) i = "0" + i;
    return i;
}

/* 1 Day */
function parseJSON() {
    var weatherAppKey = "f23961cb493d52dbd56fd0d656b3a396";

    if (weatherAppKey != "") {
        var xhr = new XMLHttpRequest;
        xhr.open("GET", "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + weatherAppKey);

        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                var a = JSON.parse(xhr.responseText);
                parseWeatherData(a);
            }
        }
        xhr.send();
    } else {
        console.log("ERROR: No App Key")
    }
}

function parseWeatherData(weatherData) {

    pageClimate.clearList();

    var temp = weatherData.main.temp - 273.15;
    var temp_min = weatherData.main.temp_min - 272.15;
    var temp_max = weatherData.main.temp_max - 272.15;
    var wind_speed = weatherData.wind.speed;                //m/sec
    var wind_direction = weatherData.wind.deg;              //angle
    var clouds = weatherData.clouds.all;                    //%
    var pressure = weatherData.main.pressure;               //hpa
    var humidity = weatherData.main.humidity;               //%
    var longitude = weatherData.coord.lon;
    var latitude = weatherData.coord.lat;
    var country = weatherData.sys.country;
    var description = weatherData.weather[0].description;
    var weathericon = weatherData.weather[0].icon;
    var sunrise = new Date(weatherData.sys.sunrise * 1000);
    var sunset = new Date(weatherData.sys.sunset * 1000);
    var sea_level = weatherData.main.sea_level;
    var grd_level = weatherData.main.grnd_level;
    var wind_deg = weatherData.wind.deg;


    /* Set Output Data */
    pageClimate.cityName = city;
    pageClimate.countryName = country;
    pageClimate.cityTemperature = temp.toFixed(2);
    pageClimate.cityDescription = description
    pageClimate.setTemperature(temp.toFixed(2), "Feels Like")
    pageClimate.setHumidity(humidity, "Humidity")
    pageClimate.setCloudiness(clouds, "Clouds")
    //pageClimate.cityLatitude = latitude;
    //pageClimate.cityLongitude = longitude;
    pageClimate.setWind(wind_speed, "Wind")
    pageClimate.setPressure(pressure, "Pressure")
    pageClimate.setSeaLevel(sea_level, "Pr. (Sea)")
    pageClimate.setGndLevel(grd_level, "Pr. (Gnd)")
    pageClimate.setwindDeg(wind_deg, "Wind Dir.")
    pageClimate.cityWeatherIcon = "http://openweathermap.org/img/w/" + weathericon + ".png"
    pageClimate.setSunrise(sunrise.getHours() + ":" + addZero(sunrise.getMinutes()), "Sunrise")
    pageClimate.setSunset(sunset.getHours() + ":" + addZero(sunset.getMinutes()), "Sunrise")
    pageClimate.weatherUpdateTime = new Date(weatherData.dt * 1000);
}


function parseWeatherData16Days(weatherData) {

    /* Clear Data */
    pageClimate.clearDayList()
    pageClimate.clearList()

    /* Push To ListView */
    for(var i = 0; i < weatherData.cnt; i++) {
        var dt = new Date(weatherData.list[i].dt * 1000);
        var mmdd = (dt.getUTCMonth() + 1) + "." + addZero(dt.getDate())
        var temp_max = weatherData.list[i].temp.max - 273.15
        var temp_min = weatherData.list[i].temp.min - 273.15
        var temp_eve = weatherData.list[i].temp.eve - 273.15
        var temp_night = weatherData.list[i].temp.night - 273.15
        var temp_morn = weatherData.list[i].temp.morn - 273.15
        var temp_day = weatherData.list[i].temp.day - 273.15
        var pressure = weatherData.list[i].pressure
        var humidity = weatherData.list[i].humidity
        var wind_speed = weatherData.list[i].speed
        var wind_deg = weatherData.list[i].deg
        var clouds = weatherData.list[i].clouds


        if(mmdd == pageClimate.dayDate) {
            pageClimate.setTemperature(temp_max.toFixed(2), "Temp Max")
            pageClimate.setTemperature(temp_min.toFixed(2), "Temp Min")
            pageClimate.setCloudiness(clouds, "Clouds")
            pageClimate.setPressure(pressure, "Pressure")
            pageClimate.setHumidity(humidity, "Humidity")
            pageClimate.setWind(wind_speed, "Wind")
            pageClimate.setwindDeg(wind_deg, "Wind Deg.")
        }

        /* Push To ListView */
        pageClimate.addDay(mmdd)
    }
}

/* 5 Days */
//function parseJSON5Days() {
//    var weatherAppKey = "f23961cb493d52dbd56fd0d656b3a396";

//    if (weatherAppKey != "") {
//        var xhr = new XMLHttpRequest;
//        xhr.open("GET", "http://api.openweathermap.org/data/2.5/forecast?q=" + city + "&appid=" + weatherAppKey +
//                 "&cnt=16");

//        xhr.onreadystatechange = function() {
//            if (xhr.readyState === XMLHttpRequest.DONE) {
//                var a = JSON.parse(xhr.responseText);
//                parseWeatherData5Days(a);
//            }
//        }
//        xhr.send();
//    } else {
//        console.log("ERROR: No App Key")
//    }
//}

function parseWeatherData5Days(weatherData) {


    /* Properties */
    var mintemp = 99;
    var maxtemp = -99;
    var maxDate = new Date();
    var pressureMin = 5000;
    var pressureMax = -5000;
    var windMin = 5000;
    var windMax = -5000;

    for(var i = 0; i < weatherData.cnt; i++) {
        var temperature = (weatherData.list[i].main.temp - 273.15).toFixed(2);
        var temperature_min = (weatherData.list[i].main.temp_min - 273.15).toFixed(2);
        var temperature_max = (weatherData.list[i].main.temp_max - 273.15).toFixed(2);
        var pressure = (weatherData.list[i].main.pressure).toFixed(2);
        var clouds = weatherData.list[i].clouds.all;
        var wind = weatherData.list[i].wind.speed;
        var date = new Date(weatherData.list[i].dt_txt);

        mintemp = Math.min(mintemp, temperature);
        maxtemp = Math.max(maxtemp, temperature);
        pressureMin = Math.min(pressureMin, pressure);
        pressureMax = Math.max(pressureMax, pressure);
        windMin = Math.min(windMin, wind);
        windMax = Math.max(windMax, wind);
        maxDate = Math.max(maxDate, date);
    }

}











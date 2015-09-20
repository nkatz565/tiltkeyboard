Pebble.addEventListener ("appmessage",
                         function(e){
                           var data=e.payload.testpost;
                           console.log("got js message"+data);
                           getStockQuote(data);
                         });
Pebble.addEventListener ("ready",
                         function(e){
                           console.log("This is JS speaking");
                           Pebble.sendAppMessage({
                             "testpost":1,
                           });
                           var value= localStorage.getItem("hellokey");
                           value++;
                           localStorage.setItem("hellokey",value);
                           console.log("value = "+value);
                         });

  



function getStockQuote(symbol){
  var xhReq = new XMLHttpRequest();
      xhReq.open("GET", "http://dev.markitondemand.com/Api/v2/Quote/xml?symbol="+symbol, false);
      xhReq.send(null);
      var x = xhReq.response;
      var ns= x.indexOf("<Name>")+6;
      var ne= x.indexOf("<",ns);
      var name=x.substr(ns,ne-ns);
      var lps=x.indexOf("<LastPrice>")+11;
      var lpe=x.indexOf("<",lps);
      var lastPrice=x.substr(lps,lpe-lps);
      var cps=x.indexOf("<ChangePercent>")+15;
      var changePercent=x.substr(cps,6);
      var hs=x.indexOf("<High>")+6;
      var he=x.indexOf("<",hs);
      var high=x.substr(hs,he-hs);
      var ls=x.indexOf("<Low>")+5;
      var le=x.indexOf("<",ls);
      var low=x.substr(ls,le-ls);
      var os=x.indexOf("<Open>")+6;
      var oe=x.indexOf("<",os);
      var open=x.substr(os,oe-os);
  console.log(name);
    console.log(lastPrice);
  console.log(changePercent);
  console.log(high);
  console.log(low);
  console.log(open);
}
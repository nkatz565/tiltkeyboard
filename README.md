# Tilt2Type

## Inspiration

We were inspired with the idea of a keyboard on the Pebble after we realized there's no way to enter text on the Pebble. We wanted to remove the process of taking your phone out of your pocket to respond to push notifications, so we realized we needed to create some way to have a full keyboard on the Pebble. Since the screen is very small, we had to be creative and utilize other features found on the Pebble. 

## What it does

Using the accelerometer and buttons, the Pebble can be tilted in five different orientations to access five sets of characters, with each set containing nine characters. By shaking the Pebble, the user can input a backspace. In addition, we demonstrated potential uses of Tilt2Type by using the MarkitOnDemand  financial data API; by entering a one to five character stock symbol and holding the select button, the user can obtain the full name and price of that particular stock. 

## How we built it

We primarily used CloudPebble, the online development kit provided by Pebble, in order to create this app. We used C to create the keyboard of the Tilt2Type app, and supplementary Javascript in order to fetch the stock quote and feed the data back to the phone. 

## Challenges we ran into

We originally developed the entire application in Javascript; we soon realized that this led to a sluggish, inoperable application that would not function the way we wanted. We learned that we needed to use C in order to have a product that we actually wanted. 

## Accomplishments that we're proud of

We learned a lot about the C language and developed an application for a market of devices that has many practical uses. In addition, our unique method of input can be the stepping stone for many future Pebble-based applications that require input more complex than buttons and accelerometer data. 

## What we learned

We learned a lot about the C language, the Pebble development kit, and how to properly design an app for a mobile interface. 

## What's next for Tilt2Text

We plan on having Tilt2Text to be used as a general keyboard since it is very minimal and can run on the same screen as other apps. We developed an application for it in order to demonstrate that the Pebble can input data independent of the phone. Optimizing the keyboard is a must to ensure that its footprint doesn't affect the usability of the apps it is implemented in.

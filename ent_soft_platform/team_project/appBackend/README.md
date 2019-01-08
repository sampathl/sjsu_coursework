#### Description

This repository contains the backend apis along with the frontend components for the catFeeder app.


#### backend

The application consists of a NoSQL database (MongoDB) to store the feed related information.  This database is accessed by the users via the frontend GUI as well as the raspberry pi via the api that are made available.

There are two apis that are created for the interaction with the database.
- /feedcat : The data is feed to this api by the enduser via the web based GUI.
- /getfeedreport : This api is used to display the latest feed data. This data can be accessed by the enduser by clicking the get report button on the GUI.
- /getData : Any requests to this api will return all the data stored in the catfeeder datastore. This data can be used for further reporting and analytics.

The frontend for the prototype is a simple form based GUI developed using the React.js library.

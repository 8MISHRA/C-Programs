const Clock = document.getElementById('clock-val');
const PoolLetters = document.getElementById('letters');
const Words = document.getElementById('words');
const user = document.getElementById('score-table-user');
const score = document.getElementById('score-table-score');
const hist = document.getElementById('hist-data');
  
// PAGE ON LOAD
window.onload = function() {
     // Code Here
	     fetch('GetState', {
        method: 'GET'
    })
	.then((response) => response.json())
	.then((data) => {
        console.log(data);
        displayInfo(data);
    })
}



var form=document.getElementById('word-form')

form.addEventListener('submit', function(e){
 e.preventDefault()

 //var user_id=document.getElementById('user_id').value
 var Pminus=document.getElementById('Pminus').value
 var Wminus=document.getElementById('Wminus').value
 var Wplus=document.getElementById('Wplus').value
 
 
 // POST request using fetch()
fetch("http://localhost/rs/scramble/api/", {
    
    // Adding method type
    method: "POST"
})

// Converting to JSON
//.then(response => response.json())

// Displaying results to console
//.then(json => console.log(json));
 
 /*

 fetch('', {
  method: 'POST'
  headers: {
    'Content-type': 'application/json; charset=UTF-8',
  }
  })
  .then(function(response){ 
  return response.json()})
  .then(function(data)
  {console.log(data) 
}).catch(error => console.error('Error:', error)); 

});*/


})


// Update rack letters
function displayInfo(data) {
	// Display Clock
	Clock.innerHTML = data.clock;
	// Pool of letters
	for (let letters of data.pool) {
		PoolLetters.innerHTML += "<input type='checkbox' class='check-letters' data-value='"+letters.toString()+"'>"+ letters.toString() +"<br/>";
	}
	// Pool of Words
	for (let words of data.words) {
		Words.innerHTML += "<input type='checkbox' class='check-words' data-value='"+words.toString()+"'>"+ words.toString() +"<br/>";
	}
	// SCORE TABLE DATA
	for (let users of data.users) {
		user.innerHTML += "<td>"+ users.name +"</td>";
	}
	for (let users of data.users) {
		score.innerHTML += "<td>"+ users.score +"</td>";
	}
	// HISTORY TABLE DATA
  if ( data.history ) { 
	for (let histori of data.history) { // added by Ramesh
		hist.innerHTML += "<td>"+histori.user+"</td><td>"+histori.score+"</td><td>"+histori.Pminus+"</td><td>"+histori.Wminus+"</td><td>"+histori.Wplus+"</td>";
	}
  }
	//console.log(hist.innerHTML);
}


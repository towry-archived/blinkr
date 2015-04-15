var fs = require('fs');
var blinkr = require('../lib');

fs.open('./slkEkjdf', 'r+', function (err) {
    if (err) {
        // blink after 2s, make sure the window is not
        // in the foreground
        setTimeout(function () {
            blinkr.blink();
        }, 2000);
    }
})

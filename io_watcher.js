var swb = require('./socket_watcher');
console.log(typeof swb.SocketWatcher);
exports.IOWatcher = typeof swb.SocketWatcher !== 'undefined' ? swb.SocketWatcher : process.binding('io_watcher').IOWatcher;
<?php include 'includes/db.php';
	if(isset($_POST['submit_bug'])){
		$date = date('Y-m-d h:i:s');
		$ins_sql = "INSERT INTO bugs (name, email, bug, date) VALUES ('$_POST[name]', '$_POST[email]', '$_POST[bug]','$date')";
		$run_sql = mysqli_query($conn,$ins_sql);
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>MyPracto</title>
		<link rel="stylesheet" href="../bootstrap/css/bootstrap.css">
		<script src="../bootstrap/js/bootstrap.js"></script>
		<script src="../js/jquery.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div class="container">
			<article class="row">
				<section class="col-lg-8">
					<div class="page-header">
						<h2>Report a bug !</h2>
					</div>
					<form class="form-horizontal" action="bug.php" method="post" role="form">
						<div class="form-group">
							<label for="name" class="col-sm-2 control-label">Name</label>
							<div class="col-sm-8">
								<input type="text" class="form-control" name="name" placeholder="Insert your Name" id="name">
							</div>
						</div>
						<div class="form-group">
							<label for="email" class="col-sm-2 control-label">Email Address</label>
							<div class="col-sm-8">
								<input type="email" class="form-control" name="email" placeholder="Email Address" id="email">
							</div>
						</div>
						<div class="form-group">
							<label for="bug" class="col-sm-2 control-label">Description of the bug</label>
							<div class="col-sm-8">
								<textarea class="form-control" rows="20" name="bug" style="resize:none;"></textarea>
							</div>
						</div>
						<div class="form-group">
							<label class="col-sm-2 control-label"></label>
							<div class="col-sm-8">
								<input type="submit" value="Report it, You might win a cool tee ;)" name="submit_bug" class="btn btn-block btn-danger" id="submit_bug">
							</div>
						</div>
					</form>
					
				</section>
				<?php include 'includes/sidebar.php';?>
			</article>
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>
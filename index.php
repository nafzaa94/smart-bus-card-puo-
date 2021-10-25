<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">

    <title>smart bus card</title>
</head>

<body>
    <div class="container">
        <form action="./senddata.php" method="POST">
            <div class="d-flex justify-content-center" style="margin-top: 100px;">
                <div class="col-6 bg-info p-3">
                    <div>
                        <h1 class="text-center">SMART BUS CARD</h1>
                    </div>
                    <div>
                        <div class="input-group mb-3">
                            <span class="input-group-text" id="basic-addon1">Name</span>
                            <input type="text" class="form-control" name="name" placeholder="name" aria-label="name" aria-describedby="basic-addon1">
                        </div>
                        <div class="input-group mb-3">
                            <span class="input-group-text" id="basic-addon1">Email</span>
                            <input type="text" class="form-control" name="email" placeholder="email" aria-label="email" aria-describedby="basic-addon1">
                        </div>
                        <div class="input-group mb-3">
                            <span class="input-group-text" id="basic-addon1">Phone</span>
                            <input type="text" class="form-control" name="phone" placeholder="phone" aria-label="phone" aria-describedby="basic-addon1">
                        </div>
                        <div class="input-group mb-3">
                            <span class="input-group-text" id="basic-addon1">ID Card</span>
                            <input type="text" class="form-control" name="id_card" placeholder="id_card" aria-label="id_card" aria-describedby="basic-addon1">
                        </div>
                        <div class="d-flex justify-content-around">
                            <div class="input-group mb-3" style="margin-right: 10px;">
                                <span class="input-group-text" id="basic-addon1">From</span>
                                <input type="text" class="form-control" name="destinationFrom" aria-label="Username" aria-describedby="basic-addon1">
                            </div>
                            <div class="input-group mb-3">
                                <span class="input-group-text" id="basic-addon1">To</span>
                                <input type="text" class="form-control" name="destinationTo" aria-label="Username" aria-describedby="basic-addon1">
                            </div>
                        </div>
                        <div class="d-flex justify-content-center">
                            <button type="submit" class="btn btn-primary">SEND</button>
                        </div>
                    </div>
                </div>
            </div>
        </form>
    </div>



    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

</body>

</html>